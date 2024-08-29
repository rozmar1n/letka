#include"SquareSolverTester.h"
#include"SquareSolver.h"
#include "file.h"
void SquareSolverTester(SquareEquation data[], int Amount)
{
    for(int i  = 0; i < Amount; i++)
    {
        pred_ans AnsPred = SquareSolver(data[i].coefficients);

        if(AnsPred.nRootsPred != data[i].answers.nRootsRef || (fabs(AnsPred.x1Pred - data[i].answers.x1Ref) > MaxDifference) ||
            (fabs(AnsPred.x2Pred - data[i].answers.x2Ref) > MaxDifference))
        {
            printf("\n\tERROR Test %d\n x1 = %lg x2 = %lg nRoots = %d a = %lg b = %lg c = %lg \n"
            "\tEXPECTED:\n x1 = %lg x2 = %lg nRoots = %d\n\n", i, AnsPred.x1Pred, AnsPred.x2Pred, AnsPred.nRootsPred, data[i].coefficients.a, data[i].coefficients.b, data[i].coefficients.c,
                                                                data[i].answers.x1Ref, data[i].answers.x2Ref, data[i].answers.nRootsRef);
        }
        else
        {
            printf("Test %d Passed\n", i);
        }
    }
}
