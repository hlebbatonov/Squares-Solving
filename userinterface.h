#ifndef USERINTERFACE_H
#define USERINTERFACE_H

enum Choise
{
    CONTINUE = 0,
    EXIT = 1,
};

void    OutputRoots             (int number_of_roots, double x1, double x2);

int     InputAllCoeffs          (double coeffs[]);

Choise  WantToContinue          ();

int     InputOneCoeff           (double *n, int *corr_input_num, int i);


#endif
