#ifndef _TextSort_H
#define _TextSort_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ForString.h"

typedef int(*compar_func_t)(char* string_1, char* string_2, int string_1_size, int string_2_size, int MaxLine);

void TextSort(char** index, int* StringsSizes, int LineAmount, int MaxLine, compar_func_t Comparator);

#endif