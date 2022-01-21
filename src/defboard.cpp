#include "functions.h"

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

int checkboard()                        
{
    short int checkValue=1;
    for(short int i=0;i<4;i++)
    {
        for(short int j=0;j<4;j++)
        {
          if(!(i==3&&j==3))
          {
              if(board[i][j]==checkValue)       
                checkValue++;                  
              else
                return 0;                      
          }
        }
    }
    return 1;                                   
}

int displayboard()                                             
{
    //system("cls");
    system("clear");
    short int zero, posI = 0, posJ = 0;                         
    short int posY=3, posX = 30;                                
    for( ; posY < 10 ; posY += 2, posI++){
        cout << endl;
        for( ; posX < 50 ; posX += 5, posJ++){
            
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
    cout << endl;
    cout<<"moves "<<moveCount << endl;              
    cout<<"esc\tpause" << endl;                           
    cout<<"w a s d move"<< endl;
    return zero;                                 
}