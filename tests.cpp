#include "common.h"
#include "solving.h"
#include "tests.h"

#define MAX_TESTS 10

const TestKeys all_tests[MAX_TESTS] =
    {
        {
            .a = 0,
            .b = 1,
            .c = -1,
            .number_of_roots_ref = NUM_OF_ROOTS_ONE,
            .x1_ref = 1,
            .x2_ref = NAN,
        },

        {
            .a = 0,
            .b = 0,
            .c = -1,
            .number_of_roots_ref = NUM_OF_ROOTS_ZERO,
            .x1_ref = NAN,
            .x2_ref = NAN,
        },

        {
            .a = 10,
            .b = 0,
            .c = -10,
            .number_of_roots_ref = NUM_OF_ROOTS_TWO,
            .x1_ref = 1,
            .x2_ref = -1,
        },

        {
            .a = 0,
            .b = 0,
            .c = 0,
            .number_of_roots_ref = NUM_OF_ROOTS_INF,
            .x1_ref = NAN,
            .x2_ref = NAN,
        },

        {
            .a = 1,
            .b = -8,
            .c = 15,
            .number_of_roots_ref = NUM_OF_ROOTS_TWO,
            .x1_ref = 5,
            .x2_ref = 3,
        },

        {
            .a = 0,
            .b = 10,
            .c = -1,
            .number_of_roots_ref = NUM_OF_ROOTS_ONE,
            .x1_ref = 0.1,
            .x2_ref = NAN,
        },

        {
            .a = 5,
            .b = 8,
            .c = -17,
            .number_of_roots_ref = NUM_OF_ROOTS_TWO,
            .x1_ref = 1.20997,
            .x2_ref = -2.80997,
        },

        {
            .a = 0,
            .b = -2,
            .c = -1,
            .number_of_roots_ref = NUM_OF_ROOTS_ONE,
            .x1_ref = -0.5,
            .x2_ref = NAN,
        },

        {
            .a = 2,
            .b = -9,
            .c = -10,
            .number_of_roots_ref = NUM_OF_ROOTS_TWO,
            .x1_ref = 5.422144,
            .x2_ref = -0.922144,
        },

        {
            .a = 0,
            .b = 1,
            .c = 0,
            .number_of_roots_ref = NUM_OF_ROOTS_ONE,
            .x1_ref = 0,
            .x2_ref = NAN,
        }
    };



int main()
{
    RunAllTests();
}

void RunAllTests()
{
    for (int i = 0; i < MAX_TESTS; i ++)
    {
        RunOneTest(all_tests[i]);
    }
}


int RunOneTest(TestKeys test)
{
    double x1 = NAN, x2 = NAN;
    double coeffs[3] = {test.a, test.b, test.c};
    NumOfRoots number_of_roots = SolveEquation(coeffs, &x1, &x2);

    if (number_of_roots == test.number_of_roots_ref)
        switch (number_of_roots)
        {
            case NUM_OF_ROOTS_INF: case NUM_OF_ROOTS_ZERO:
                if (isnan(x1) && isnan(x2) && isnan(test.x1_ref) && isnan(test.x2_ref))
                    PRINT_OK();
                else
                    PRINT_FAILED();

               break;

            case NUM_OF_ROOTS_ONE:
                if (IsEqual(x1, test.x1_ref) && isnan(x2) && isnan(test.x2_ref))
                    PRINT_OK();
                else
                    PRINT_FAILED();

                break;

            case NUM_OF_ROOTS_TWO:
                if (IsEqual(x1, test.x1_ref) && IsEqual(x2, test.x2_ref))
                    PRINT_OK();
                else
                    PRINT_FAILED();

               break;

            default:
                assert((number_of_roots >= -1 && number_of_roots <= 2) && "Error! invalid number of roots");
        }
    else
       PRINT_FAILED();

    return 0;
}
