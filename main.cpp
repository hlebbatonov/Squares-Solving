#include "common.h"
#include "tests.h"


int main()
{

    printColor(BG_WHITE, "%s %s\n\n", HEAD, VERSION);

    while (true)
    {
        HandleWithOneEquation();

        if (WantToContinue() == EXIT) return 0;
    }
}



