#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#include"ForIndexes.h"
#include"ForString.h"
#include"TextSort.h"

const short MaxLine = 160;
const int AmountOfLines = 36;

const char *text[] ={
        "My uncle - high ideals inspire him;",
        "but when past joking he fell sick,",
        "he really forced one to admire him --",
        "and never played a shrewder trick.",
        "Let others learn from his example!",
        "But God, how deadly dull to sample",
        "sickroom attendance night and day",
        "and never stir a foot away!",
        "And the sly baseness, fit to throttle,",
        "of entertaining the half-dead:",
        "one smoothes the pillows down in bed,",
        "and glumly serves the medicine bottle,",
        "and sighs, and asks oneself all through:",
        "Such were a young rake's meditations --",
        "by will of Zeus, the high and just,",
        "\"When will the devil come for you?\"",
        "the legatee of his relations --",
        "as horses whirled him through the dust.",
        "Friends of my Ruslan and Lyudmila,",
        "without preliminary feeler",
        "let me acquaint you on the nail",
        "with this the hero of my tale:",
        "Onegin, my good friend, was littered",
        "and bred upon the Neva's brink,",
        "where you were born as well, I think,",
        "reader, or where you've shone and glittered!",
        "There once I too strolled back and forth:",
        "but I'm allergic to the North...1",
        "After a fine career, his father",
        "had only debts on which to live.",
        "He gave three balls a year, and rather",
        "promptly had nothing left to give.",
        "Fate saved Evgeny from perdition:",
        "at first Madame gave him tuition,",
        "from her Monsieur took on the child.",
        "He was sweet-natured, and yet wild."
        };

//void PutText(const char *TextFile, const char** text);
void OutputConstText(const char** textik, int LineAmount);
void MakeIndex(const char** textik, const char* index[]);




int main(void)
{
    const char* textikus[MaxLine];
    
    /*PutText("onegin.txt", textikus);
    const char* string_indexus[AmountOfLines] = {0};
    MakeIndex(textikus, string_indexus);
    OutputConstText(string_indexus, AmountOfLines);*/

    const char* string_indexes[AmountOfLines] = {0};
    MakeIndex(text, string_indexes, AmountOfLines);

    OutputConstText(string_indexes, AmountOfLines);
    TextSort(string_indexes, AmountOfLines, MaxLine);

    printf("\n");
    printf("\n");
    printf("\n");
    OutputConstText(string_indexes, AmountOfLines);
}

/*void PutText(const char *TextFile, const char** text)
{
    FILE *OneginText = fopen(TextFile, "w");
    if(OneginText == NULL)
    {
        fprintf(stderr, "We cannot open your file!\n");
        return;
    }
    else
    {
        int i = 0;
        int j = 0;
        char buffer;
        while(fread(&buffer, sizeof(buffer), 1, OneginText))
        {
            if (buffer == '\r\n')
            {
                
            }
            
            *(index[i] + i) = buffer;
            i++;
        }
        printf("%s", text[0]);
        fclose(OneginText);        
    }    
}*/




