/**@file*/

#include "file.h"
#include"coefs.h"
#include"SquareSolver.h"
#include "SquareSolverTester.h"
//#include"Istest.h"

//TODO: csv file with tests

///Test data for our Equation Solver
/*static square_equation data[]
{
    {.coefficients = {0,    0,   0},   .solutions = {NAN,   NAN,  -1}},
    {.coefficients = {1,   -5,   6},   .solutions = {3,     2,     2}},
    {.coefficients = {1,   -2,   1},   .solutions = {1,     1,     1}},
    {.coefficients = {1,    3,   2},   .solutions = {-1,   -2,     2}},
    {.coefficients = {2,   -4,   2},   .solutions = {1,     1,     1}},
    {.coefficients = {1,    0,   4},   .solutions = {NAN,   NAN,   0}},
    {.coefficients = {1,    2,   5},   .solutions = {NAN,   NAN,   0}},
    {.coefficients = {3,    1,   2},   .solutions = {NAN,   NAN,   0}},
    {.coefficients = {2,    0,   8},   .solutions = {NAN,   NAN,   0}},
    {.coefficients = {1,   -4,   5},   .solutions = {NAN,   NAN,   0}},
    {.coefficients = {0.5, -1.5, 0.5}, .solutions = {2.618, 0.382, 2}}
};*/

int main()
{
    square_eq_coef coefficients {.a = NAN, .b = NAN, .c = NAN};

    /*!
        \brief Conditional compilation

        In the first case, we want to enter our own coefficients
        but in the second one, the code will perform the check itself without requiring us to enter anything.
    */

    #if 0

    InputCoef(&coefficients);
    CoefExam(&coefficients);

    pred_sol prog_res = SquareSolver(coefficients);
    OutputResults(prog_res);

    #else

    SquareSolverTester("TestData.csv");

    #endif
}








