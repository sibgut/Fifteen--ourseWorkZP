#include "functions.h"

bool issolvable(int board[szb][szb])
{
    int sc = 1;
    for (int i = 0; i < szb; i++)
        for (int j = 0; j < szb; j++)
            if (board[i][j] != sc++)
                if (!(i == szb - 1 && j == szb - 1))
                    return false;
    return true;
}
