#include"TextSort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ForString.h"


void TextSort(const char* index[], int LineAmount, int MaxLine)
{
    //OutputConstText(index, LineAmount);
    
    char temp_string1[MaxLine];
    char temp_string2[MaxLine];
    
    char i,
         j;
    
    for (int index_elem = 0; index_elem < LineAmount - 1; index_elem++)
    {
        for (int compar_elem = 0; compar_elem < LineAmount - 1; compar_elem++)
        {
            i = 0;
            j = 0;
            while(*(index[compar_elem] + i) != '\0' && i < strlen(index[compar_elem]))
            {
                if (isalpha(*(index[compar_elem] + i )))
                {
                    temp_string1[j] = *(index[compar_elem] + i); 
                    ToLower(temp_string1 + j);
                    i++;
                    j++; 
                    }
                else
                {
                    i++;
                }    
            }

            temp_string1[j] = '\0';

            i = 0;
            j = 0;
            while(*(index[compar_elem + 1] + i) != '\0' && i < strlen(index[compar_elem + 1]))
            {
                if (isalpha(*(index[compar_elem + 1] + i )))
                {
                    temp_string2[j] = *(index[compar_elem + 1] + i); 
                    ToLower(temp_string2 + j);
                    i++;
                    j++; 
                    }
                else
                {
                    i++;
                }    
            }
            temp_string2[j] = '\0';

            if(Comparator(temp_string1, temp_string2, MaxLine))
            {
               SwapStrings(index, compar_elem, compar_elem + 1);
            }
            memset (temp_string1, 0, sizeof(temp_string1));
            memset (temp_string2, 0, sizeof(temp_string2));
        }
    }
}