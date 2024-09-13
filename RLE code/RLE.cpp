#include<stdio.h>
#include<string.h>

void RLEencryption(char* string);

int main(void)
{
    char* string = NULL;
    printf("Enter the string:  ");
    scanf("%s", string);

    char* cipher = NULL;
    RLEencryption(string);
}

void RLEencryption(char* string)
{
    char now = '\0',
         before = '\0';
    char buffer[128];
    //char* ciphr = NULL;
    int inside = 0;
    char number = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        before = now;
        now = *(string + i);

        if (inside)
        {
            if (now == before)
            {
                number += 1;
            }
            else
            {
                printf("%d %c;", 128 + number, now);
                number = 0;
                inside = 0;    
            }
        }
        else
        {
            if (now != before)
            {
                buffer[number] = now;
                number += 1;
            }
            else
            {
                printf("%d",number);
                for (int j = 0; j < number; j++)
                {
                    printf(" %c", buffer[j]); 
                    buffer[j] = NULL;   
                }
                printf(";");
                number = 0;
                inside = 0;
            }
        }
    }
}