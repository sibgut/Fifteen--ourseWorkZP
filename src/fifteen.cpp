<<<<<<< HEAD
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

=======
#include "functions.h"

int main()
{
    while(1)
    {
        readSuccess=readStats();
        titlescreen();
        gameOn();
        updateStats();
        cout<<"WIN WIN WIN";
        system("pause");
        reset();
    }
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

int checksolvable()                                             
{
    int invcount=0,GREATER,boardlist[16]={ 0 },num1,posI,posJ;
    for(posI=0;posI<4;posI++)
    {
        for(posJ=0;posJ<4;posJ++)
        {
            if(board[posI][posJ])
            {
                GREATER=0;
                for(num1=0;boardlist[num1];num1++)
                {
                    if(board[posI][posJ]>boardlist[num1]&&boardlist[num1])
                        GREATER++;
                }
                invcount+=board[posI][posJ]-GREATER-1;
                boardlist[num1]=board[posI][posJ];
            }
        }
    }
    return(invcount%2);                                         
}

bool readStats()                            
{
   fstream data;
   data.open("file",ios::in|ios::binary);  
   if(!data)                                
   {
       stored.MATCHES=stored.MOVES=stored.TIME=stored.MINMOVES=stored.MINTIME=0;
       return false;                        
   }
   data.read((char*)&stored,sizeof(stats));
   data.close();
   return true;                            
}

char input(char Low)
{
    return (Low>90)?Low-=32:Low;                                
}

void displayStopwatch(){
    cout<<"time "<<((CURR-START)/1000)/60<<" : "<<((CURR-START)/1000)%60<<"."<<((CURR-START)%1000)/100<<"     ";
}

void reset()                                                
{
    moveCount=0;
    firstHit=false;
}

void pausemenu()
{
    char pauseop;
    do{
        cout << "***********GAME PAUSED*********************** \n Esc resume \n N new game \n E exit" << endl;  
        pauseop=input(getchar());
        if(pauseop=='N')               
        {
            reset();          
            cout<<"\tRESTARTING...";
            reset();
            gameOn();
            break;
        }
        else if(pauseop=='E')         
        {
            reset();
            main();
        }
    }while(pauseop!=27);               
}

void stopwatch(int toggle)  
{
    if(toggle==0)          
        CURR=clock();       
    else if(toggle==1)      
        START=clock();      
    else                    
    {
        pausemenu();            
        START+=(clock()-CURR);  
    }
}

void swapfunc(short int *x,short int *y)
{
    short int temp=(*x);
    (*x)=(*y);
    (*y)=temp;
}

bool inputhandler(int zero)
{
    int oI=zero/10;
    int oJ=zero%10;                     
    bool keyHit = false;
    char MOVE;                          
    if(getchar())                         
    {
        MOVE=input(getchar());
        firstHit=true;                  
        keyHit = true;
    }
    stopwatch(0);                       
    if(!firstHit)                       
        stopwatch(1);                  
    if((MOVE=='W')&&(oI!=0))            
    {
        swapfunc(&board[oI-1][oJ],&board[oI][oJ]);
        moveCount++;
    }
    else if((MOVE=='A')&&(oJ!=0))       
    {
        swapfunc(&board[oI][oJ-1],&board[oI][oJ]);
        moveCount++;
    }
    else if((MOVE=='S')&&(oI!=3))       
    {
        swapfunc(&board[oI+1][oJ],&board[oI][oJ]);
        moveCount++;
    }
    else if((MOVE=='D')&&(oJ!=3))       
    {
        swapfunc(&board[oI][oJ+1],&board[oI][oJ]);
        moveCount++;
    }
    else if(MOVE==27)                   
    {
        cout<<"     ";
        stopwatch(-1);                  
    }
    return keyHit;
}

void gameOn()                           
{
    do{
            createboard();
    }while(checksolvable());        
    int zero = displayboard();                      
    do{
        if(inputhandler(zero)){
            zero=displayboard();    
        }
        // displayStopwatch();                         
    }while(!checkboard());          
}

void updateStats()                         
{
    if(readSuccess)                         
    {
        if(moveCount<stored.MINMOVES)       
            stored.MINMOVES=moveCount;
        if((CURR-START)<stored.MINTIME)
            stored.MINTIME=(CURR-START);
    }
    else
    {
        stored.MINMOVES=moveCount;          
        stored.MINTIME=(CURR-START);
    }
    stored.MATCHES++;                       
    stored.TIME+=(CURR-START);             
    stored.MOVES+=moveCount;
    fstream writ;
    writ.open("file",ios::out|ios::binary);    
    writ.write((char*)&stored,sizeof(stats));
    writ.close();
}

void statsView()                            
{
  char option;
  system("clear");
  cout<<"TOTAL GAMES PLAYED\t"<<left<<setw(10)<<stored.MATCHES<< endl;  
  cout<<"TOTAL TIME PLAYED\t"<<((stored.TIME)/1000)/60<<" : "<<((stored.TIME)/1000)%60<<"."<<((stored.TIME)%1000)/100<<" " << endl;
  cout<<"TOTAL MOVES\t"<<right<<setw(12)<<stored.MOVES << endl;
  cout<<"MIN TIME IN ONE GAME\t"<<(stored.MINTIME/1000)/60<<" : "<<((stored.MINTIME)/1000)%60<<"."<<((stored.MINTIME)%1000)/100 << endl;
  cout<<"MIN MOVES IN ONE GAME\t"<<stored.MINMOVES << endl ;
  if(readSuccess)                          
  {
      cout<<"AVERAGE TIME"<<setw(10)<<((stored.TIME/stored.MATCHES)/1000)/60<<" : "<<((stored.TIME/stored.MATCHES)/1000)%60<<"."<<((stored.TIME/stored.MATCHES)%1000)/100 << endl;
      cout<<"AVERAGE MOVES\t"<<(stored.MOVES/stored.MATCHES) << endl;
  }
  cout<<"B\t back" << endl;
  do{
    
    option=input(getchar());
  }while(option!='B');
}

void titlescreen()                          
{
    char option;
    title:
    // system("cls");
    system("clear");
    cout << "Coursework fifteen \n N NEW GAME \n S STATISTICS \n Q QUIT" << endl;     
    option=input(getchar());
    if(option=='N')                         
    {
        cout<<"start";
        return;                             
    }
    else if(option=='S')                    
    {
        statsView();
        goto title;
    }
    else if(option=='Q')                    
    {
        cout<<"Y\tCONFIRM";
        option=input(getchar());
        if(option=='Y'){
            // system("cls");
            system("clear");
            exit(0);                                               
        }
        else
            goto title;
    }
    else
        goto title;
}
>>>>>>> 0cbb731d6c0fd6508924dce25cff759bb044c84b
