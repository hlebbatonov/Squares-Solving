#include "solving.h"

NumOfRoots SolveEquation(double coeffs[], double *x1, double *x2)
{

    if (IsEqual(coeffs[DEGREE - 3], 0))
        return (SolveLinear(coeffs, x1));

    else
        return (SolveSquare(coeffs, x1, x2));

}

int IsEqual(double a, double b)
{
    return ((fabs(a - b) < ACCURACY) ? 1: 0);
}

double CalculateDiscriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

NumOfRoots SolveLinear(double coeffs[], double *x1)
{
    //solve equation: bx + c = 0
    double b = coeffs[DEGREE - 2], c = coeffs[DEGREE - 1];

    if (IsEqual(b, 0))
    {
        if (IsEqual(c, 0))
            return NUM_OF_ROOTS_INF;
        else
            return NUM_OF_ROOTS_ZERO;
    }

    else
    {
        *x1 = -c / b;
        return NUM_OF_ROOTS_ONE;
    }
}

NumOfRoots SolveSquare(double coeffs[], double *x1, double *x2)
{
    //solve equation: ax^2 + bx + c = 0
    double a = coeffs[DEGREE - 3], b = coeffs[DEGREE - 2], c = coeffs[DEGREE - 1];

    double discriminant = RoundDoubleToZero(CalculateDiscriminant(a, b, c));

    double sqrt_discriminant = 0;

    if (discriminant < 0) return NUM_OF_ROOTS_ZERO;

    else if (IsEqual(discriminant, 0))
    {
        *x1 = -b / ( 2 * a);
        return NUM_OF_ROOTS_ONE;
    }

    else
    {
        sqrt_discriminant = sqrt(discriminant);

        *x1 = (-b + sqrt_discriminant) / (2 * a);
        *x2 = (-b - sqrt_discriminant) / (2 * a);
        return NUM_OF_ROOTS_TWO;
    }
}

double RoundDoubleToZero(double fraction)
{
    return ((IsEqual(fraction, 0) ? 0: fraction));
}
