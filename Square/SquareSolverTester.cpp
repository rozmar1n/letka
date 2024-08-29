#include"SquareSolverTester.h"
#include"SquareSolver.h"
#include "file.h"

void SquareSolverTester(const char *TestFile)
{
    /*for(int i  = 0; i < Amount; i++)
    {
        pred_ans AnsPred = SquareSolver(data[i].coefficients);

        if(AnsPred.nRootsPred != data[i].solutions.nRootsRef || (fabs(AnsPred.x1Pred - data[i].solutions.x1Ref) > MaxDifference) ||
            (fabs(AnsPred.x2Pred - data[i].solutions.x2Ref) > MaxDifference))
        {
            printf("\n\tERROR Test %d\n x1 = %lg x2 = %lg nRoots = %d a = %lg b = %lg c = %lg \n"
            "\tEXPECTED:\n x1 = %lg x2 = %lg nRoots = %d\n\n", i, AnsPred.x1Pred, AnsPred.x2Pred, AnsPred.nRootsPred, data[i].coefficients.a, data[i].coefficients.b, data[i].coefficients.c,
                                                                data[i].solutions.x1Ref, data[i].solutions.x2Ref, data[i].solutions.nRootsRef);
        }
        else
        {
            printf("Test %d Passed\n", i);
        }
    }*/
    square_equation test{};

    //char buffer[1000], *ch;

    //unsigned int test_number = 1;

    FILE *tests_data = fopen(TestFile, "r");

    if(tests_data == NULL)
    {
        printf("ERROR: could not open file\n");
        exit(0);
    }
    else
    {
        #if 0
        while (fgets(buffer, sizeof(buffer), tests_data)/*fscanf(tests_data, "%lg, %lg, %lg, %lg, %lg, %d", &test.coefficients.a, &test.coefficients.b, &test.coefficients.c, &test.solutions.x1Ref, &test.solutions.x2Ref, &test.solutions.nRootsRef) != EOF*/)
        {
            /*test.coefficients.a = strtod(buffer, &ch);
            test.coefficients.b = strtod(ch, &ch);
            test.coefficients.c = strtod(ch, &ch);
            test.solutions.x1Ref = strtod(ch, &ch);
            test.solutions.x2Ref = strtod(ch, &ch);
            test.solutions.nRootsRef = atoi(ch);*/



            /*test.coefficients.a = strtod(strtok(buffer, ";"), &ch);
            test.coefficients.b = strtod(strtok(NULL, ";"), &ch);
            test.coefficients.c = strtod(strtok(NULL, ";"), &ch);
            test.solutions.x1Ref= strtod(strtok(NULL, ";"), &ch);
            test.solutions.x2Ref= strtod(strtok(NULL, ";"), &ch);
            test.solutions.nRootsRef= atoi(strtok(NULL, ";"));
            printf("%lg, %lg, %lg, %lg, %lg, %d\n", test.coefficients.a, test.coefficients.b, test.coefficients.c, test.solutions.x1Ref, test.solutions.x2Ref, test.solutions.nRootsRef);*/

            //RunTest(test, &test_number);
        }
        #endif
        unsigned int test_number = 1;
        do
        {
            int read = 0;


            read = fscanf(tests_data,
                          "%lg;%lg;%lg;%lg;%lg;%d\n",
                          &test.coefficients.a,
                          &test.coefficients.b,
                          &test.coefficients.c,
                          &test.solutions.x1Ref,
                          &test.solutions.x2Ref,
                          &test.solutions.nRootsRef);


            //printf("%lg, %lg, %lg, %lg, %lg, %d\n", test.coefficients.a, test.coefficients.b, test.coefficients.c, test.solutions.x1Ref, test.solutions.x2Ref, test.solutions.nRootsRef);


            if(read != 6 && !feof(tests_data))
            {
                printf("File format incorrect.\n");
                exit(0);
            }

            if(ferror(tests_data))
            {
                printf("ERROR reading file.\n");
                exit(0);
            }

            RunTest(test, test_number);
            test_number++;

        }while(!feof(tests_data));

        fclose(tests_data);

    }
}
void RunTest(square_equation test, unsigned int test_number)
{
    pred_sol AnsPred = SquareSolver(test.coefficients);


    if(AnsPred.nRootsPred != test.solutions.nRootsRef || (fabs(AnsPred.x1Pred - test.solutions.x1Ref) > MaxDifference) ||
            (fabs(AnsPred.x2Pred - test.solutions.x2Ref) > MaxDifference))
        {
            printf("\n\tERROR Test %d\n x1 = %lg x2 = %lg nRoots = %d a = %lg b = %lg c = %lg \n"
            "\tEXPECTED:\n x1 = %lg x2 = %lg nRoots = %d\n\n", test_number, AnsPred.x1Pred, AnsPred.x2Pred, AnsPred.nRootsPred, test.coefficients.a, test.coefficients.b, test.coefficients.c,
                                                                test.solutions.x1Ref, test.solutions.x2Ref, test.solutions.nRootsRef);
        }
        else
        {
            printf("Test %d Passed\n", test_number);
        }
}

