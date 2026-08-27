#ifndef SOLVING_H
#define SOLVING_H
#include "common.h"

// TODO: rename NumOfRoots
// TODO: NUM_OF_ROOTS_ZERO
enum NumOfRoots
{
    NUM_OF_ROOTS_INF = -1,
    NUM_OF_ROOTS_ZERO,
    NUM_OF_ROOTS_ONE,
    NUM_OF_ROOTS_TWO
};


NumOfRoots   SolveEquation           (double coeffs[], double *x1, double *x2);

int     IsEqual                 (double a, double b);

double  CalculateDiscriminant   (double a, double b, double c);

NumOfRoots   SolveLinear             (double coeffs[], double *x1);

NumOfRoots   SolveSquare             (double coeffs[], double *x1, double *x2);

double  RoundDoubleToZero       (double fraction);


#endif
