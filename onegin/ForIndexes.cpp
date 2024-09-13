#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ForIndexes.h"

void MakeIndex(const char** textik, const char* index[], int AmountOfLines)
{
    for (int string_number = 0; string_number < AmountOfLines; string_number++)
        index[string_number] = textik[string_number];   
    return;
}

void OutputConstText(const char** textik, int LineAmount)
{
    for (int string_number = 0; string_number < LineAmount; string_number++)
    {
        printf("%s\n", textik[string_number]);
    }
}