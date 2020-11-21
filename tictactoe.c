#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

//set console cursor position in windows, and more
#include <conio.h>
#include <windows.h>

//record moves in an array; 2 = empty, 0 = X, 1 = O
int moves[9];

int y = 2;
int dy = 7;

void board(void)
{
    printf(" 1 | 2 | 3\n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6\n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9\n");

    return;
}

void pos(int x, int y)
{
    COORD cursor;
    cursor.X = x;
    cursor.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

bool win(int X_O)
{
    //horizontal win
    if (moves[0] == X_O && moves[1] == X_O && moves[2] == X_O)
    {
        return true;
    }
    if (moves[3] == X_O && moves[4] == X_O && moves[5] == X_O)
    {
        return true;
    }
    if (moves[6] == X_O && moves[7] == X_O && moves[8] == X_O)
    {
        return true;
    }

    //vertical win
    if (moves[0] == X_O && moves[3] == X_O && moves[6] == X_O)
    {
        return true;
    }
    if (moves[1] == X_O && moves[4] == X_O && moves[7] == X_O)
    {
        return true;
    }
    if (moves[2] == X_O && moves[5] == X_O && moves[8] == X_O)
    {
        return true;
    }

    //diagonal win
    if (moves[0] == X_O && moves[4] == X_O && moves[8] == X_O)
    {
        return true;
    }
    if (moves[2] == X_O && moves[4] == X_O && moves[6] == X_O)
    {
        return true;
    }

    return false;
}

void place_X_O(int X_O)
{
    int x = 1;

    //default x and y cursor coords
    int dx = 0;

    char xo;
    if (X_O == 0)
    {
        xo = 'X';
    }
    else
    {
        xo = 'O';
    }

    char input;
    do
    {
        input = getch();

        switch(input)
        {
            case '1':
                if (moves[0] != 2)
                {
                    continue;
                }
                moves[0] = X_O;
                pos(x, y);
                printf("%c", xo);

                return;
            case '2':
                if (moves[1] != 2)
                {
                    continue;
                }
                moves[1] = X_O;
                pos(x + 4, y);
                printf("%c", xo);

                return;
            case '3':
                if (moves[2] != 2)
                {
                    continue;
                }
                moves[2] = X_O;
                pos(x + 8, y);
                printf("%c", xo);

                return;
            case '4':
                if (moves[3] != 2)
                {
                    continue;
                }
                moves[3] = X_O;
                pos(x, y + 2);
                printf("%c", xo);

                return;
            case '5':
                if (moves[4] != 2)
                {
                    continue;
                }
                moves[4] = X_O;
                pos(x + 4, y + 2);
                printf("%c", xo);

                return;
            case '6':
                if (moves[5] != 2)
                {
                    continue;
                }
                moves[5] = X_O;
                pos(x + 8, y + 2);
                printf("%c", xo);

                return;
            case '7':
                if (moves[6] != 2)
                {
                    continue;
                }
                moves[6] = X_O;
                pos(x, y + 4);
                printf("%c", xo);

                return;
            case '8':
                if (moves[7] != 2)
                {
                    continue;
                }
                moves[7] = X_O;
                pos(x + 4, y + 4);
                printf("%c", xo);

                return;
            case '9':
                if (moves[8] != 2)
                {
                    continue;
                }
                moves[8] = X_O;
                pos(x + 8, y + 4);
                printf("%c", xo);

                return;
        }
    }
    while(1);
    return;
}

int play(void)
{
    board();

    for (int i = 0; i < 9; i++)
    {
        moves[i] = 2;
    }

    int X_O = 0;
    int n = 0;
    while (1)
    {
        X_O = 0;
        place_X_O(X_O);
        pos(0, dy);
        if (win(X_O) == 1)
        {
            printf("\nX WAS THE WINNER!\n\n");
            break;
        }
        n++;
        if (n == 9)
        {
            printf("\nTHERE WAS A TIE! YOU BOTH LOST.\n\n");
            break;
        }

        X_O = 1;
        place_X_O(X_O);
        pos(0, dy);
        if (win(X_O) == 1)
        {
            printf("\nO WAS THE WINNER!\n\n");
            break;
        }
        n++;

        //debug; see what moves are recorded in the array
        //for (int i = 0; i < 9; i++)
        //{
            //printf("%i", moves[i]);
        //}
    }

    return 0;
}

int main(void)
{
    system("cls");
    system("title Tic Tac Toe - https://github.com/hugegains");
    printf("Press your number keys to place an X or O at the corresponding positions on the board.\n\n");
    do
    {
        play();
        y += 8;
        dy = y + 5;
    }
    while(1);
}