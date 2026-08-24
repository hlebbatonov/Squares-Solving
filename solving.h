#ifndef SOLVING_H
#define SOLVING_H
#include "common.h"

enum Roots
{
    INF = -1,
    ZERO,
    ONE,
    TWO
};


Roots   SolveEquation           (double coeffs[], double *x1, double *x2);

int     IsEqual                 (double a, double b);

double  CalculateDiscriminant   (double a, double b, double c);

Roots   SolveLinear             (double coeffs[], double *x1);

Roots   SolveSquare             (double coeffs[], double *x1, double *x2);

double  RoundDoubleToZero       (double fraction);


#endif
