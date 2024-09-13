#include"ForString.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void SwapStrings(const char* index[], int string_1, int string_2)
{
    const char* temp_ptr = NULL;
    temp_ptr = index[string_1];
    index[string_1] = index[string_2];
    index[string_2] = temp_ptr; 
}

int Comparator(char* string_1, char* string_2, int MaxLine)
{
    for (int symbol = 0; symbol < MaxLine; symbol++)
    {
        //printf("string_1[symbol]:  %c", string_1[symbol]);
        //printf("string_2[symbol]:  %c", string_2[symbol]);
        if(string_1[symbol] > string_2[symbol])
        {
            return 1;
        }
        if(string_1[symbol] < string_2[symbol])
        {
            return 0;
        }
    }
}

void ToLower(char* symbol)
{
    if (isupper(*symbol))
    {
        *symbol = *symbol + 'a' - 'A';    
    }      
}