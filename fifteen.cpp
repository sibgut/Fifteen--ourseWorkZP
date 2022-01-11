#include <iostream>

using namespace std;

void createboard();

struct stats {
    int MATCHES; 
    int MOVES;
    long int TIME;
    int MINMOVES;
    int MINTIME;
} stored;

short int board[4][4];

int main()                                 
{
    return 0;
}

void createboard()                                      
{
    short int value=1,posI,posJ;                        
    for(posI=0;posI<4;posI++)
    {
        for(posJ=0;posJ<4;posJ++)
            board[posI][posJ]=0;                        
    }
    while(value<16)
    {
        posI=rand()%4;
        posJ=rand()%4;                                  
        if(posI*posJ!=9)                                
        {
            if(board[posI][posJ]==0)
            {
                board[posI][posJ]=value;                
                value++;
            }
        }
    }
}