#include "common.h"
#include "colorprinting.h"
#include "userinterface.h"
#include "solving.h"
#include "clearbuffer.h"

#define RANGE 10e10

void OutputRoots(int number_of_roots, double x1, double x2)
{
    printf("\n");

    switch(number_of_roots)
        {
            case ZERO:

                printColor(YELLOW, "No roots");

                break;

            case ONE:
                printf("Single root: x = ");

                printColor(GREEN, "%lg", RoundDoubleToZero(x1));

                break;

            case TWO:
                printf("Two roots: x1 = ");

                printColor(GREEN, "%lg", RoundDoubleToZero(x1));

                printf(",    x2 = ");

                printColor(GREEN, "%lg", RoundDoubleToZero(x2));

                break;

            default:
                printf("Equation has an infinite number of solutions");
                break;
        }

    printf("\n\n");
}

int InputAllCoeffs(double coeffs[])
{
    printf("Input coefficients of square equation");

    printColor(WHITE, " \"ax^2 + bx + c = 0\":\n");

    InputVerdict correct_input_coeff = OK;

    int failed_index = 0;

    for (int i = 0; i < DEGREE; i++)
    {
        if (correct_input_coeff != OK)
        {
            failed_index = i - 1;
            break;
        }
        correct_input_coeff = InputOneCoeff(&coeffs[i], i);
    }

    switch (correct_input_coeff)
    {
        case NOTANUM:
            printColor(RED, "Entered coefficient %c is not a number", failed_index + 'a');
            return 1;
            break;
        case TOOBIG:
            printColor(RED, "Entered coefficient %c is out of range", failed_index + 'a');
            return 1;
            break;
        case OK: default:
            return 0;
            break;

        }
    if (correct_input_coeff == OK)
        return 1;
    else
        return 0;
}

InputVerdict InputOneCoeff(double *n, int i)
{
    printf("%c: ", i + 'a');

    SET_TEXT_CYAN();
    int corr_input_num = scanf("%lf", n);
    RESET();

    if (ClearBuffer() == 0 || corr_input_num == 0)
        return NOTANUM;
    else if (fabs(*n) > RANGE)
        return TOOBIG;
    else
        return OK;
}

Choise WantToContinue()
{
    while (true)
    {
        char decision = ' ';
        int corr_input_decision = 1;

        printColor(YELLOW, "\n1) Solve new equation\t");
        printColor(WHITE, "2) Exit\n");

        printf("Input a number: ");

        SET_TEXT_CYAN();
        corr_input_decision = scanf(" %c", &decision);
        RESET();

        if (decision == END && corr_input_decision == 1 && ClearBuffer() == 1)
        {
            printColor(WHITE, "\nBye-bye!");

            return EXIT;
            break;
        }

        else if (decision == NEWEQUATION && corr_input_decision == 1 && ClearBuffer() == 1)
        {

            return CONTINUE;
            break;
        }

        else
        {

            printColor(RED, "\nEntered invalid number\n");
        }

    }
}
