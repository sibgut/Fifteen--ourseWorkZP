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
void displayboardFrame(){                                       
    short int ypos = 2, posX = 29, posY = 2;
    system("cls");
    for( ; posY < 10 ; ++posY){
        cursorLocation(posX, posY++);
        cout<<"+----+----+----+----+";                        
        for( ; posX < 50 ; posX += 5){
            cursorLocation(posX, posY);
            printf("|");
        }
        posX = 29;   
    }
    cursorLocation(posX, posY);
    cout<<"+----+----+----+----+";  
}

int displayboard()                                              
{
    short int zero, posI = 0, posJ = 0;                         
    short int posY=3, posX = 30;                                
    for( ; posY < 10 ; posY += 2, posI++){
        for( ; posX < 50 ; posX += 5, posJ++){
            cursorLocation(posX, posY);
            if(board[posI][posJ]){
                cout<<right<<setw(4)<<board[posI][posJ];
            }
            else{
                cout<<"    ";
                zero = (10 * posI) + posJ;
            }
        }
        posJ = 0;
        posX = 30;
    }
    cursorLocation(27, 12);
    cout<<"COUNTS "<<moveCount; 
    cursorLocation(3, 14);
    cout<<"Esc\tPAUSE";
    cursorLocation(3, 16);
    cout<<"W A S D";
    return zero;
}

void displayStopwatch(){
    cursorLocation(40,12);
    cout<<"TIME "<<((CURR-START)/1000)/60<<" : "<<((CURR-START)/1000)%60<<"."<<((CURR-START)%1000)/100<<"     ";
}