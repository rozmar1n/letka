#include "file.h"
#include"coefs.h"
#include"SquareSolver.h"
#include "SquareSolverTester.h"
//BatScript - написать
//создал гит репозиторий

static SquareEquation data[]
{

    {.coefficients = {0, 0, 0}, .answers = {NAN, NAN, -1}},
    {.coefficients = {1, -5, 6}, .answers = {3, 2, 2}},
    {.coefficients = {1, -2, 1}, .answers = {1, 1, 1}},
    {.coefficients = {1, 3, 2}, .answers = {-1, -2, 2}},
    {.coefficients = {2, -4, 2}, .answers = {1, 1, 1}},
    {.coefficients = {1, 0, 4}, .answers = {NAN, NAN, 0}},
    {.coefficients = {1, 2, 5}, .answers = {NAN, NAN, 0}},
    {.coefficients = {3, 1, 2}, .answers = {NAN, NAN, 0}},
    {.coefficients = {2, 0, 8}, .answers = {NAN, NAN, 0}},
    {.coefficients = {1, -4, 5}, .answers = {NAN, NAN, 0}},
    {.coefficients = {0.5, -1.5, 0.5}, .answers = {2.618, 0.382, 2}}

};

int main()
{
    square_eq_coef coefficients {.a = NAN, .b = NAN, .c = NAN};

    InputCoef(&coefficients);
    coef_exam(&coefficients);

    pred_ans ProgRes = SquareSolver(coefficients);
    OutputResults(ProgRes);

    SquareSolverTester(data, sizeof(data)/sizeof(data[0]));
}








