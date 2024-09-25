#ifndef _ForString_H
#define _ForString_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* MakeGoodText(char* text, int TextSize);
void SwapStrings(char* index[], int string_1, int string_2);
void SwapSizes(int* StringSizes, int elem_1, int elem_2);
int Comparator_1(char* string_1, char* string_2, int string_1_size, int string_2_size, int MaxLine);
int Comparator_2(char* string_1, char* string_2, int string_1_size, int string_2_size, int MaxLine);

#endif