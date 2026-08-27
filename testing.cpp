#include "common.h"
#include "solving.h"

#define MAX_TESTS 10

struct TestKeys
{
    double a, b, c;
    int number_of_roots_ref;
    double x1_ref, x2_ref;
};

const TestKeys all_tests[MAX_TESTS] =
    {
        {
            .a = 0,
            .b = 1,
            .c = -1,
            .number_of_roots_ref = ONE,
            .x1_ref = 1,
            .x2_ref = 0,
        },

        {
            .a = 0,
            .b = 0,
            .c = -1,
            .number_of_roots_ref = ZERO,
            .x1_ref = 0,
            .x2_ref = 0,
        },

        {
            .a = 10,
            .b = 0,
            .c = -10,
            .number_of_roots_ref = TWO,
            .x1_ref = 1,
            .x2_ref = -1,
        },

        {
            .a = 0,
            .b = 0,
            .c = 0,
            .number_of_roots_ref = INF,
            .x1_ref = 0,
            .x2_ref = 0,
        },

        {
            .a = 1,
            .b = -8,
            .c = 15,
            .number_of_roots_ref = TWO,
            .x1_ref = 5,
            .x2_ref = 3,
        },

        {
            .a = 0,
            .b = 10,
            .c = -1,
            .number_of_roots_ref = ONE,
            .x1_ref = 0.1,
            .x2_ref = 0,
        },

        {
            .a = 5,
            .b = 8,
            .c = -17,
            .number_of_roots_ref = TWO,
            .x1_ref = 1.20997,
            .x2_ref = -2.80997,
        },

        {
            .a = 0,
            .b = -2,
            .c = -1,
            .number_of_roots_ref = ONE,
            .x1_ref = -0.5,
            .x2_ref = 0,
        },

        {
            .a = 2,
            .b = -9,
            .c = -10,
            .number_of_roots_ref = TWO,
            .x1_ref = 5.422144,
            .x2_ref = -0.922144,
        },

        {
            .a = 0,
            .b = 1,
            .c = 0,
            .number_of_roots_ref = ONE,
            .x1_ref = 0,
            .x2_ref = 0,
        }
    };

void RunAllTests();

int RunOneTest(TestKeys test);


int main()
{

    RunAllTests();

}

void RunAllTests()
{
    // NOTE: do you know about designators?
    for (int i = 0; i < MAX_TESTS; i ++)
    {
        RunOneTest(all_tests[i]);
    }
}


int RunOneTest(TestKeys test)
{
    double x1 = 0, x2 = 0;
    double coeffs[3] = {test.a, test.b, test.c};
    NumOfRoots number_of_roots = SolveEquation(coeffs, &x1, &x2);

    // TODO: in future: think about NAN (initialization and NAN-tests)
    if (number_of_roots != test.number_of_roots_ref || !IsEqual(x1, test.x1_ref) || !IsEqual(x2, test.x2_ref))
    {
        printf("Test FAILED: a = %lg, b = %lg, c = %lg\n"
               "REFERENCE: %d roots, x1_ref = %lg, x2_ref = %lg\n"
               "GOT: %d roots, x1 = %lg, x2 = %lg\n",
               test.a, test.b, test.c, test.number_of_roots_ref, test.x1_ref, test.x2_ref, number_of_roots, x1, x2);
    }
    else
        printf("Test OK\n");

    return 0;
}
