#ifndef USERINTERFACE_H
#define USERINTERFACE_H

enum Choise
{
    CONTINUE = 0,
    EXIT = 1,
};

enum UsersInput
{
    NEWEQUATION = '1',
    END = '2'
};

enum InputVerdict
{
    OK = 0,
    NOTANUM = 1,
    TOOBIG = 2
};

void         OutputRoots    (int number_of_roots, double x1, double x2);

int          InputAllCoeffs (double coeffs[]);

Choise       WantToContinue ();

InputVerdict InputOneCoeff  (double *n, int i);


#endif
