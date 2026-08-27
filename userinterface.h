#ifndef USERINTERFACE_H
#define USERINTERFACE_H

enum Choise
{
    CHOISE_CONTINUE = 0,
    CHOISE_EXIT = 1,
};

enum UsersInput
{
    INPUT_NEWEQUATION = '1',
    INPUT_END = '2'
};

enum InputVerdict
{
    VERDICT_OK = 0,
    VERDICT_NOTANUM = 1,
    VERDICT_TOOBIG = 2
};

void         OutputRoots    (int number_of_roots, double x1, double x2);

int          InputAllCoeffs (double coeffs[]);

Choise       WantToContinue ();

InputVerdict InputOneCoeff  (double *n, int i);


#endif
