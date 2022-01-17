#include "functions.h"

int main()
{
    windowSetup();
    while(1)
    {
        readSuccess=readStats();
        titlescreen();
        gameOn();
        updateStats();
        cursorLocation(3, 14);
        cout<<"WIN WIN WIN";
        cursorLocation(3, 16);
        system("pause");
        reset();
    }
    return 0;
}

void windowSetup()
{
    srand((unsigned)time(NULL));                       
    COORD coord={80,30};
    SMALL_RECT Rect={0,0,79,29};
    CONSOLE_CURSOR_INFO lpCursor = {1, false};          
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitleA("oneFIVE++");
    SetConsoleWindowInfo(console, TRUE, &Rect);        
    SetConsoleScreenBufferSize(console, coord);         
    SetConsoleCursorInfo(console, &lpCursor);           
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

BOOL cursorLocation(const WORD x,const WORD y)              
{
    COORD coordinates;                                      
    coordinates.X=x;
    coordinates.Y=y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}

void menuoutline(const string &main,const string &op1,const string &sel1,const string &op2,const string &sel2,const string &op3,const string &sel3)     
{
    cursorLocation(3,12);
    cout<<main;
    cursorLocation(3,14);
    cout<<op1<<"\t"<<sel1;
    cursorLocation(3,16);
    cout<<op2<<"\t"<<sel2;
    cursorLocation(3,18);
    cout<<op3<<"\t"<<sel3;
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

char input(char Low)
{
    return (Low>90)?Low-=32:Low;                                
}

void displayboardFrame(){                                       
    short int ypos = 2, posX = 29, posY = 2;
    system("cls");
    for( ; posY < 10 ; ++posY){
        cursorLocation(posX, posY++);
        cout<<"*********************";                        
        for( ; posX < 50 ; posX += 5){
            cursorLocation(posX, posY);
            printf("*");
        }
        posX = 29;   
    }
    cursorLocation(posX, posY);
    cout<<"*********************";  
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
    cout<<"moves "<<moveCount;              
    cursorLocation(3, 14);
    cout<<"esc\tpause";                           
    cursorLocation(3, 16);
    cout<<"w a s d move";
    return zero;                                 
}

void displayStopwatch(){
    cursorLocation(40,12);
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
        menuoutline("pause","esc","resume","n","new game","e","quit");
        cursorLocation(0,29);
        pauseop=input(getch());
        if(pauseop=='N')               
        {
            reset();
            cursorLocation(3,20);
            cout<<"\trestart...";
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
    cursorLocation(0,29);
    if(kbhit())                         
    {
        MOVE=input(getch());
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
        cursorLocation(3, 16);
        cout<<"     ";
        stopwatch(-1);                  
        displayboardFrame();
    }
    return keyHit;
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

void gameOn()                           
{
    do{
            createboard();
    }while(checksolvable());        
    displayboardFrame();
    int zero = displayboard();                      
    do{
        if(inputhandler(zero)){
            zero=displayboard();    
        }
        displayStopwatch();                         
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
  system("cls");
  menuoutline("stats","\0","\0","\0","\0","\0","\0");
  cursorLocation(3,14);
  cout<<"total games\t"<<left<<setw(10)<<stored.MATCHES;
  cursorLocation(3,16);
  cout<<"total time\t"<<((stored.TIME)/1000)/60<<" : "<<((stored.TIME)/1000)%60<<"."<<((stored.TIME)%1000)/100<<" ";
  cursorLocation(3,18);
  cout<<"total moves\t"<<right<<setw(12)<<stored.MOVES;
  cursorLocation(3,20);
  cout<<"min time\t"<<(stored.MINTIME/1000)/60<<" : "<<((stored.MINTIME)/1000)%60<<"."<<((stored.MINTIME)%1000)/100;
  cursorLocation(3,22);
  cout<<"min moves\t"<<stored.MINMOVES;
  cursorLocation(3,24);
  if(readSuccess)                           
  {
      cout<<"avg time"<<setw(10)<<((stored.TIME/stored.MATCHES)/1000)/60<<" : "<<((stored.TIME/stored.MATCHES)/1000)%60<<"."<<((stored.TIME/stored.MATCHES)%1000)/100;
      cursorLocation(3,26);
      cout<<"avg moves\t"<<(stored.MOVES/stored.MATCHES);
      cursorLocation(3,28);
  }
  cout<<"b\tback";
  do{
    cursorLocation(0,29);
    option=input(getch());
  }while(option!='B');
}

void titlescreen()                          
{
    char option;
    title:
    system("cls");
    menuoutline("Coursework fifteen","n","new game","s","stats","q","quit");      
    cursorLocation(0,29);
    option=input(getch());
    if(option=='N')                         
    {
        cursorLocation(8,20);
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
        cursorLocation(8,20);
        cout<<"Y\tCONFIRM";
        cursorLocation(0,29);
        option=input(getch());
        if(option=='Y'){
            system("cls");
            exit(0);                                               
        }
        else
            goto title;
    }
    else
        goto title;
}