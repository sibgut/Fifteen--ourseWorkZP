#ifndef FUNCTION_H
#define FUNCTION_H

#include<stdlib.h>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdbool.h>
#include <stdio.h>

using namespace std;

struct stats{           
    int MATCHES;        
    int MOVES;          
    long int TIME;      
    int MINMOVES;       
    int MINTIME;        
}stored;

short int board[4][4];   
int _kbhit();
int START = 0,CURR = 0;     
int moveCount=0;        
bool firstHit=false;   
bool readSuccess;       
bool readStats();       
void createboard();
int checksolvable();
char input(char);
int displayboard();
void reset();
void pausemenu();
void stopwatch(int);
void displayStopwatch();
bool inputhandler(int);
int checkboard();
void gameOn();
void updateStats();
void statsView();
void titlescreen();
void swapfunc(short int*,short int*);


#endif
