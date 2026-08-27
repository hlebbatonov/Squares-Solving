#ifndef TESTS_H
#define TESTS_H

#include "common.h"

#define PRINT_FAILED() printf("Test FAILED: a = %lg, b = %lg, c = %lg\n"\
               "REFERENCE: %d roots, x1_ref = %lg, x2_ref = %lg\n"\
               "GOT: %d roots, x1 = %lg, x2 = %lg\n",\
               test.a, test.b, test.c, test.number_of_roots_ref, test.x1_ref, test.x2_ref, number_of_roots, x1, x2)

#define PRINT_OK() printf("Test OK\n")

struct TestKeys
{
    double a, b, c;
    int number_of_roots_ref;
    double x1_ref, x2_ref;
};

void RunAllTests ();
int  RunOneTest  (TestKeys test);

#endif
