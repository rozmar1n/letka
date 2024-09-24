#include<stdio.h>
#include"TXLib.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ForIndexes.h"
#include"ForString.h"
#include"TextSort.h"

const char* stringa = "always contented with his life,";

char* PutText(const char *TextFile, long* TextSize);

int main(void)
{

    char* text = NULL;
    long TextSize = 0;
    
    text = PutText("onegin.txt", &TextSize);

    char** string_indexus = NULL;
    int AmountOfLines = 0;
    int MaxLine = 0;

    int* lines = NULL;

    string_indexus = MakeIndex(text, &AmountOfLines, TextSize, &MaxLine, &lines);
    

    TextSort(string_indexus, lines, AmountOfLines, MaxLine, Comparator_1);
    OutputByIndexes(string_indexus, AmountOfLines);
}

char* PutText(const char *TextFile, long* TextSize)
{
    FILE *OneginText = fopen(TextFile, "r");
    char* buffer = NULL;
    
    if(!OneginText)
    {
        fprintf(stderr, "We cannot open your file!\n");
        return buffer;
    }
    else
    {
        fseek(OneginText, 0, SEEK_END);
        long OneginSize = ftell(OneginText);

        buffer = (char*)calloc(OneginSize + 1, sizeof(char));

        rewind(OneginText);
        fread(buffer, sizeof(char), OneginSize, OneginText);
        fclose(OneginText);
        buffer[OneginSize + 1] = '\0';
        
        *TextSize = OneginSize + 1;
        return buffer;
    }    
}




