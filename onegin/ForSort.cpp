#include"ForSort.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* MakeGoodText(char* text, int TextSize)
{
    char* GoodText = NULL;
    GoodText = (char*)calloc(TextSize, sizeof(char));

    int j = 0;
    for (int symbol = 0; symbol < TextSize; symbol++)
    {
        if (isalpha(text[symbol]) || text[symbol] == '\n')
        {
            GoodText[j] = text[symbol];
            tolower(*(GoodText + j));
            j++; 
        }
    }
    return GoodText;
}

void SwapStrings(char* index[], int string_1, int string_2)
{
    char* temp_ptr = NULL;
    temp_ptr = index[string_1];
    index[string_1] = index[string_2];
    index[string_2] = temp_ptr; 
}

void SwapSizes(int* StringSizes, int elem_1, int elem_2)
{
    int temp_elem = StringSizes[elem_1];
    StringSizes[elem_1] = StringSizes[elem_2];
    StringSizes[elem_2] = temp_elem;
}

int Comparator_1(char* string_1, char* string_2, int string_1_size, int string_2_size, int MaxLine)
{
    int i = 0, j = 0;
    for (int symbol = 0; symbol < MaxLine; symbol++)
    {
        if((isalpha(string_1[i]) || string_1[i] == '\0' || string_1[i] == '\n') && (isalpha(string_2[j])|| string_2[j] == '\0' || string_2[j] == '\n'))
        {
            if(tolower(string_1[i])  > tolower(string_2[j]))
            {
                return 1; 
            }
            if(tolower(string_1[i])  < tolower(string_2[j]))
            {
                return 0;
            }
            i++;
            j++;
        }
        else
        {
            if (!isalpha(string_1[i]))
            {
                i++;
            }
            if (!isalpha(string_2[j]))
            {
                j++;
            } 
        }

    }
}

int Comparator_2(char* string_1, char* string_2, int string_1_size, int string_2_size, int MaxLine)
{
    int i = string_1_size;
    int j = string_2_size;
    for (int symbol = 0; symbol < MaxLine; symbol++)
    {
        if((isalpha(string_1[i]) || string_1[i] == '\0' || string_1[i] == '\n') && (isalpha(string_2[j])|| string_2[j] == '\0' || string_2[j] == '\n'))
        {
            if(tolower(string_1[i])  > tolower(string_2[j]))
            {
                return 1; 
            }
            if(tolower(string_1[i])  < tolower(string_2[j]))
            {
                return 0; 
            }
                i--;
                j--;
        }
        else
        {
            if (!isalpha(string_1[i]))
            {
                i--;
            }
            if (!isalpha(string_2[j]))
            {
                j--;
            } 
        }

    }
}