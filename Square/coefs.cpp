#include"coefs.h"
#include"file.h"

void ClearBuffer()
{
    char ch = '\0';
    while(ch != '\n' && ch != EOF)
    {
        ch = char(getchar());
    }
}

void InputCoef(square_eq_coef* coefficients)
{
    printf("Введите коэффициенты вашего квадратного уравнения через пробел и нажмите Enter:  ");

    int temp = 0;
    char ch = '\0';

    printf("\nВведите первый коэффициент:  ");
    while(temp < 1)
    {
        temp +=scanf("%lg", &coefficients->a);
        if(temp < 1)
        {
            ch = char(getchar());
        }
        if(ch == EOF)
        {
            printf("НЕВЕРНЫЙ ВВОД\n");
            exit(0);
        }
    }
    printf("Введите второй коэффициент:  ");
    while(temp < 2)
    {

        temp +=scanf("%lg", &coefficients->b);
        if(temp < 2)
        {
            ch = char(getchar());
        }
        if(ch == EOF)
        {
            printf("НЕВЕРНЫЙ ВВОД\n");
            exit(0);
        }
    }
    printf("Введите третий коэффициент:  ");
    while(temp < 3)
    {
        temp +=scanf("%lg", &coefficients->c);
        if(temp < 3)
        {
            ch = char(getchar());
        }
        if(ch == EOF)
        {
            printf("НЕВЕРНЫЙ ВВОД\n");
            exit(0);
        }
    }
    ClearBuffer();
}

void  OutputResults(pred_ans results)
{
    switch(results.nRootsPred)
    {
        case 0:
            printf("У вашего уравнения нет корней\n");
            break;
        case 1:
            printf("У вашего уравнения один корень:  %lg\n", results.x1Pred);
            break;
        case 2:
            printf("Первый корень вашего уравнения:  %lg\n"
                   "Второй корень вашего уравнения:  %lg\n", results.x1Pred, results.x2Pred);
            break;
        case -1:
            printf("У вашего уравнения бесконечное число решений!\n");
            break;
        default:
            printf("Что-то пошло не так...");
            exit(0);
    }
}
void coef_exam(square_eq_coef* coefficients)
{
    if(coefficients->a != coefficients->a || coefficients->b != coefficients->b || coefficients->c != coefficients->c)
    {
        printf("\nВВОД ВЫПОЛНЕН НЕВЕРНО!!!\n");
        char ch = '\0';
        while(ch != '\n')
        {
            ch = char(getchar());
        }
        if(ch == EOF)
        {
            exit(0);
        }
        ClearBuffer();
        InputCoef(coefficients);
        coef_exam(coefficients);
    }
    else
    {
            printf("Ваши коэффицинты:\n"
           "Первый коэффициент:  %lg \n"
           "Второй коэффициент:  %lg \n"
           "Третий коэффициент:  %lg \n\n"
           "Если все верно введите 1 и нажмите Enter, в противном случае введите 0:   ", coefficients->a, coefficients->b, coefficients->c);

        int result = 2;


        int temp = scanf("%d", &result);
        switch(result)
        {
            case 1:
                printf("Супер!\n\n");
                break;
            case 0:
                printf("Жаль, давайте попробуем еще раз\n");
                InputCoef(coefficients);
                coef_exam(coefficients);
                break;
            default:
                printf("Вы ввели не тот символ, давайте попробуем еще раз\n");
                if(temp)
                {
                    coef_exam(coefficients);
                }
                break;
        }
    }
}
