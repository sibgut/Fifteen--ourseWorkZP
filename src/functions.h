#ifndef FUNCTION_H
#define FUNCTION_H

#include<iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;
#define szb 4

void gameOn(int board[szb][szb]);
void fillrandom(int board[szb][szb]);
void displayboard(int board[szb][szb]);
bool issolvable(int board[szb][szb]);

#endif
