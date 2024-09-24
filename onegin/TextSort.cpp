#include"TextSort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ForString.h"

void TextSort(char** index, int* StringsSizes, int LineAmount, int MaxLine, compar_func_t Comparator)
{
    for (int index_elem = 0; index_elem < LineAmount - 1; index_elem++)
    {
        for (int compar_elem = 0; compar_elem < LineAmount - 1; compar_elem++)
        {
            if(Comparator(index[compar_elem], index[compar_elem + 1], StringsSizes[compar_elem], StringsSizes[compar_elem + 1], MaxLine))
            {
               SwapStrings(index, compar_elem, compar_elem + 1);
               SwapSizes(StringsSizes, compar_elem, compar_elem + 1);
            }
        }
    }
}