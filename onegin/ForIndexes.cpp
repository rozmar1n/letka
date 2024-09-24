#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ForIndexes.h"

char** MakeIndex(char* textik, int* AmountOfLines, int TextSize, int* MaxLine, int** lines)//РїРµСЂРµРґРµР»Р°С‚СЊ РґР»СЏ С‡С‚РµРЅРёСЏ РёР· С„Р°Р№Р»Р°
{
    char symbol = '\0';
    int nstrings = 0;
    char** indexes;

    indexes = (char**)calloc(1, sizeof(char*));
    int* lines_in_func = *lines;

    lines_in_func = (int*)calloc(1, sizeof(int));


    indexes[0] = &(textik[0]);

    int ThatString = 0; 
    
    int MaxString = 0;
    
    
    for (size_t i = 0; i < TextSize; i++)
    {
        symbol = textik[i];
        ThatString += 1;
        if (symbol != '\r')
        {
            if (symbol == '\n')
            {
                lines_in_func[nstrings] = ThatString;
                nstrings++;
                
                textik[i] = '\0';
                indexes[nstrings] = &(textik[i + 1]);
                if (MaxString < ThatString)
                {
                    MaxString = ThatString; 
                }
                ThatString = 0;
            }
        }
        else
        {
            textik[i] = '\0';
        }
        if (i != TextSize)
        {
            indexes = (char**)realloc(indexes, (nstrings + 2)*sizeof(char*));  
            lines_in_func = (int*)realloc(lines_in_func, (nstrings + 1)*sizeof(int));  
        }
    }

    lines_in_func[nstrings] = 0;

    *AmountOfLines = nstrings;
    *MaxLine = MaxString;
    *lines = lines_in_func;

    return indexes;
}

void OutputByIndexes(char** indexes, int AmountOfLines)
{
    for (int string_number = 0; string_number < AmountOfLines + 1; string_number++)
    {
        printf("%d string: %s\n", string_number, indexes[string_number]);
    }
}