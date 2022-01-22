#include "ctest.h"
#include "functions.h"

CTEST(is_solvable, ConditionIsWin)
{
    int board[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i][j] = i * 4 + j + 1;
    bool result = issolvable(board);
    ASSERT_TRUE(result);
}

CTEST(is_solvable, ConditionIsWrong1)
{
    int board[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i][j] = 0;
    bool result = issolvable(board);
    ASSERT_FALSE(result);
}

CTEST(is_solvable, ConditionIsWrong2)
{
    int board[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i][j] = i;
    bool result = issolvable(board);
    ASSERT_FALSE(result);
}

CTEST(is_solvable, ConditionIsWrong3)
{
    int board[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i][j] = j;
    bool result = issolvable(board);
    ASSERT_FALSE(result);
}

CTEST(is_solvable, ConditionIsWrong4)
{
    int board[4][4];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            board[i][j] = i + j;
    bool result = issolvable(board);
    ASSERT_FALSE(result);
}
