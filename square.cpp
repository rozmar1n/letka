#include "TXLib.h" // TXLib.h must be on the first line
#include<stdio.h>
#include<math.h>
#include<string.h>



const int ALOT = -1;

int Solver(double* coefficients, double* x1, double* x2);

void InputCoef(double* coefficients);

void coef_exam(double* coefficients);

 // TODO too many blank lines

int main()
{
    double coefficients[] {NAN, NAN, NAN},
                          x1, x2;
                                               // TODO init your variables (NAN for double)
    InputCoef(coefficients);
    coef_exam(coefficients);

    int nResults = ALOT;
    nResults = Solver(coefficients, &x1, &x2);

    // Make separate function
    // Read about enum
    switch(nResults)
    {
        case 1: printf("� ������ ��������� ���� ������:  %lg\n", x1);
                break;

        case 0: printf("� ������ ��������� ��� ������\n");
                break;

        case 2: printf("������ ������ ������ ���������:  %lg\n"
                       "������ ������ ������ ���������:  %lg\n", x1, x2);
                break;

        case 3: printf("� ������ ��������� ��� ����� � ����������� ����������:  %lg\n", x1);
                break;
        case ALOT: printf("� ������ ��������� ����������� ����� �������!\n");
                   break;

        default: printf("���-�� ����� �� ���...");
    }

}

// TODO use const for coeffs array
int Solver(double* coefficients, double* x1, double* x2)
{
    double a = coefficients[0], b = coefficients[1], c = coefficients[2];


    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if(a == 0)
    {
        printf("���� ��������� �� �������� ����������, �� �����...\n");
        if(b == 0)
        {
            if(c == 0)
            {
                return ALOT;
            }

            return 0;
        }
        else
        {
            *x1 = -(coefficients[2])/(coefficients[1]);
            return 1;
        }
    }
    double D;
    D = b*b - 4*a*c;
    if(D < 0.0)
    {
        return 0;
    }

    *x1 = (-b + sqrt(D))/(2*a);
    *x2 = (-b - sqrt(D))/(2*a);
    if (*x1 == *x2)
    {
        return 11;
    }
    return 2;
}

void InputCoef(double* coefficients)
{
    printf("������� ������������ ������ ����������� ��������� ����� ������ � ������� Enter:  ");

    int i = 0, temp = scanf("%lg", coefficients + i);
    i += temp;
    char ch = '\0';
    while(i < 3)
    {
        while(temp != 1)
        {
            ch = getchar();
            temp = scanf("%lg", coefficients + i);
            i += temp;
        }
        if(i < 3)
        {
            temp = scanf("%lg", coefficients + i);
            i += temp;
        }
    }

    // TODO separate function
    while(ch != '\n')
    {
        ch = getchar();
    }


}


// const and blank lines
void coef_exam(double* coefficients)
{
    printf("���� �����������:\n"
           "������ �����������:  %lg \n"
           "������ �����������:  %lg \n"
           "������ �����������:  %lg \n\n"
           "���� ��� ����� ������� 1 � ������� Enter, � ��������� ������ ������� 0:   ", coefficients[0], coefficients[1], coefficients[2]);

    int result = 2;
    char ch = '\0';

    scanf("%d", &result);

    switch(result)
    {
        // printf on a new line
        case 1: printf("�����!\n\n");
                break;

        case 0: printf("����, ������� ��������� ��� ���\n");
                InputCoef(coefficients);
                coef_exam(coefficients);
                break;

        default: printf("�� ����� �� ��� ������, ������� ��������� ��� ���\n");

                 coef_exam(coefficients);

                 break;
    }
}
