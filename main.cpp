#include "common.h"
#include "solving.h"
#include "clearbuffer.h"
#include "userinterface.h"
#include "colorprinting.h"


static void HandleWithOneEquation();

int main()
{
    printColor(BG_WHITE, "%s %s\n\n", HEAD, VERSION);

    while (true)
    {
        HandleWithOneEquation();

        if (WantToContinue() == CHOISE_EXIT) return 0;
    }
}

static void HandleWithOneEquation()
{
    double coeffs[DEGREE] = {};
    double x1 = NAN, x2 = NAN;
    enum NumOfRoots number_of_roots = NUM_OF_ROOTS_ZERO;

    if (InputAllCoeffs(coeffs) != 0)
    {
        printf("\n");
    }
    else
    {
        number_of_roots = SolveEquation(coeffs, &x1, &x2);
        OutputRoots(number_of_roots, x1, x2);
    }
}
