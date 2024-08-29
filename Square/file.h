#ifndef FILE_H
#define FILE_H

#include "TXLib.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void ClearBuffer();
struct Ref
{
    double x1Ref, x2Ref;
    int nRootsRef;
};
struct square_eq_coef
{
    double a;
    double b;
    double c;
};
struct SquareEquation
{
    square_eq_coef coefficients;
    Ref answers;
};
struct pred_ans
{
    double x1Pred, x2Pred;
    int nRootsPred;
};
const double MaxDifference = 0.001;

#endif
