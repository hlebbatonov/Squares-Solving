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

        if (WantToContinue() == EXIT) return 0;
    }
}

static void HandleWithOneEquation()
{
    double coeffs[DEGREE] = {};
    double x1 = 0, x2 = 0;
    enum Roots number_of_roots = ZERO;

    if (InputAllCoeffs(coeffs) != 0)
    {
        printf("\n\n");

    }
    else
    {
        number_of_roots = SolveEquation(coeffs, &x1, &x2);
        OutputRoots(number_of_roots, x1, x2);
    }
}





