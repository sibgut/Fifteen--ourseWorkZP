#include "functions.h"
// int moveCount=0;

int main()
{   
    srand(time(NULL));
    int board[szb][szb] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};
    fillrandom(board);
    gameOn(board);
    return 0;
}
void gameOn(int board[szb][szb])
{
    int posI;
    int posJ;
    int temp;
    char code;
    for (int i = 0; i < szb; i++)
        for (int j = 0; j < szb; j++) {
            if (board[i][j] == 0) {
                posI = i;
                posJ = j;
            }
        }
    while (true) {
        system("clear");
        displayboard(board);
        code = getchar();
        if (code == 'q')
            break;
        switch (code) {
        case 65:
        case 97:
            if (posJ > 0) {
                temp = board[posI][posJ - 1];
                board[posI][posJ - 1] = board[posI][posJ];
                board[posI][posJ] = temp;
                posJ--;
                //moveCount++;
            }
            break;
        case 68:
        case 100:
            if (posJ < szb - 1) {
                temp = board[posI][posJ + 1];
                board[posI][posJ + 1] = board[posI][posJ];
                board[posI][posJ] = temp;
                posJ++;
                //moveCount++;
            }
            break;
        case 87:
        case 119:
            if (posI > 0) {
                temp = board[posI - 1][posJ];
                board[posI - 1][posJ] = board[posI][posJ];
                board[posI][posJ] = temp;
                posI--;
                //moveCount++;
            }
            break;
        case 83:
        case 115:
            if (posI < szb - 1) {
                temp = board[posI + 1][posJ];
                board[posI + 1][posJ] = board[posI][posJ];
                board[posI][posJ] = temp;
                posI++;
                //moveCount++;
            }
        }
        if (issolvable(board)) {
            cout << "\nWIN WIN WIN\n";
            break;
        }
    }
}
void fillrandom(int board[szb][szb])
{
    int i = 0, j = 0, k, tmp1, tmp2;
    int tmp;
    char t = 0;

    for (k = 0; k < szb; ++k) {
        while (i < szb) {
            j = 0;

            while (j < szb) {
                while ((tmp1 = rand() % szb)
                       == (tmp2 = rand() % szb))
                    ;

                if (t) {
                    tmp = board[i][tmp1];
                    board[i][tmp1] = board[i][tmp2];
                    board[i][tmp2] = tmp;
                    t = !t;
                } else {
                    tmp = board[tmp1][j];
                    board[tmp1][j] = board[tmp2][j];
                    board[tmp2][j] = tmp;
                    t = !t;
                }
                ++j;
            }
            ++i;
            t = !t;
        }
    }
}
void displayboard(int board[szb][szb])
{
    int i, j;
	cout << "Coursework fifteen" << endl;
    for (i = 0; i < szb; i++) {
        for (j = 0; j < szb; j++) {
            if (board[i][j] == 0)
                cout << "    ";
            else
                cout << setw(4) << board[i][j];
        }
        cout << "\n\n";
    }
    //cout<<"moves "<<moveCount << endl;
	cout<<"w a s d move"<< endl;
	cout<<"q - to quit"<< endl;
}
