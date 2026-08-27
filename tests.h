#ifndef TESTS_H
#define TESTS_H

#include "common.h"

struct TestKeys
{
    double a, b, c;
    int number_of_roots_ref;
    double x1_ref, x2_ref;
};

void RunAllTests ();
int  RunOneTest  (TestKeys test);

#endif
