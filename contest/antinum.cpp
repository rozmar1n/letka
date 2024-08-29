#include<stdio.h>

int minus_of_int(int x)
{
    int minus_x = x*(-1);
    return minus_x;
}

int main()
{
    int a = -8;
    printf("%d", minus_of_int(a));
}