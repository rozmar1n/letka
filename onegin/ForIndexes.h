#ifndef _ForIndexes_H
#define _ForIndexes_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void OutputByIndexes(char** indexes, int AmoutOfLines);
char** MakeIndex(char* textik, int* AmountOfLines, int TextSize, int* MaxLine, int** lines);

#endif