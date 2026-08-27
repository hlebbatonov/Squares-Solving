#include "common.h"
#include "colorprinting.h"
#include "userinterface.h"
#include "solving.h"
#include "clearbuffer.h"

#define RANGE 1e10

void OutputRoots(int number_of_roots, double x1, double x2)
{
    printf("\n");

    switch(number_of_roots)
    {
        case NUM_OF_ROOTS_ZERO:
            printColor(YELLOW, "No roots");
            break;

        case NUM_OF_ROOTS_ONE:
            printf("Single root: x = ");
            printColor(GREEN, "%lg", RoundDoubleToZero(x1));
            break;

        case NUM_OF_ROOTS_TWO:
            printf("Two roots: x1 = ");
            printColor(GREEN, "%lg", RoundDoubleToZero(x1));
            printf(",    x2 = ");
            printColor(GREEN, "%lg", RoundDoubleToZero(x2));
            break;

        case NUM_OF_ROOTS_INF:
            printf("Equation has an infinite number of solutions");
            break;

        default:
            assert((number_of_roots < -1 || number_of_roots > 2) && "Error! invalid number of roots");
    }

    printf("\n");
}

int InputAllCoeffs(double coeffs[])
{
    printf("Input coefficients of square equation");
    printColor(WHITE, " \"ax^2 + bx + c = 0\":\n");

    InputVerdict correct_input_coeff = VERDICT_OK;

    int failed_index = 0;

    for (int i = 0; i < DEGREE; i++)
    {
        if (correct_input_coeff != VERDICT_OK)
        {
            failed_index = i - 1;
            break;
        }
        correct_input_coeff = InputOneCoeff(&coeffs[i], i);
    }

    switch (correct_input_coeff)
    {
        case VERDICT_NOTANUM:
            printColor(RED, "Entered coefficient %c is not a number", failed_index + 'a');
            return 1;
            break;

        case VERDICT_TOOBIG:
            printColor(RED, "Entered coefficient %c is out of range", failed_index + 'a');
            return 1;
            break;

        case VERDICT_OK: default:
            return 0;
            break;
    }
    if (correct_input_coeff == VERDICT_OK)
        return 1;
    else
        return 0;
}

InputVerdict InputOneCoeff(double *n, int i)
{
    int corr_input_num = 0;

    printf("%c: ", i + 'a');
    SET_TEXT_CYAN();
    corr_input_num = scanf("%lf", n);
    RESET();

    if (ClearBuffer() == 0 || corr_input_num == 0)
        return VERDICT_NOTANUM;
    else if (fabs(*n) > RANGE)
        return VERDICT_TOOBIG;
    else
        return VERDICT_OK;
}

Choise WantToContinue()
{
    while (true)
    {
        char decision = 0;
        int corr_input_decision = 1;

        printColor(YELLOW, "\n1) Solve new equation\t");
        printColor(WHITE, "2) Exit\n");

        printf("Input a number: ");
        SET_TEXT_CYAN();
        corr_input_decision = scanf(" %c", &decision);
        RESET();

        if (decision == INPUT_END && corr_input_decision == 1 && ClearBuffer() == 1)
        {
            printColor(WHITE, "Bye-bye!");

            return CHOISE_EXIT;
            break;
        }
        else if (decision == INPUT_NEWEQUATION && corr_input_decision == 1 && ClearBuffer() == 1)
        {
            return CHOISE_CONTINUE;
            break;
        }
        else
        {
            printColor(RED, "Entered invalid number\n");
        }
    }
}
