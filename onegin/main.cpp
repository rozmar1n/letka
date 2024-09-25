#include"TXLib.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ForIndexes.h"
#include"ForSort.h"
#include"TextSort.h"

int main(int argc, char *argv[])
{

    char* text = NULL;
    long TextSize = 0;
    
    if (argc > 1)
    {
        text = PutText(argv[1], &TextSize);
    }
    else
    {
        text = PutText("onegin.txt", &TextSize);
    }

    char** string_indexus = NULL;
    int AmountOfLines = 0;
    int MaxLine = 0;
    int* string_sizes = NULL;

    string_indexus = MakeIndex(text, &AmountOfLines, TextSize, &MaxLine, &string_sizes);
    
    TextSort(string_indexus, string_sizes, AmountOfLines, MaxLine, Comparator_1);
    OutputByIndexes(string_indexus, AmountOfLines);
    return 0;
}