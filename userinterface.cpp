#include "common.h"
#include "colorprinting.h"
#include "userinterface.h"
#include "solving.h"
#include "clearbuffer.h"

void OutputRoots(int number_of_roots, double x1, double x2)
{
    printf("\n");



    switch(number_of_roots)
        {
            case ZERO:

                printColor(YELLOW, "Нет корней");

                break;

            case ONE:
                printf("Единственный корень: x = ");

                printColor(GREEN, "%lg", RoundDoubleToZero(x1));

                break;

            case TWO:
                printf("Два корня: x1 = ");

                printColor(GREEN, "%lg", RoundDoubleToZero(x1));

                printf(",    x2 = ");

                printColor(GREEN, "%lg", RoundDoubleToZero(x2));

                break;

            default:
                printf("Уравнение имеет бесконечное множество решений");
                break;
        }

    printf("\n\n");
}

int InputAllCoeffs(double coeffs[])
{
    int corr_num[DEGREE] = {};


    printf("Введите коэффициенты квадратного уравнения вида");

    printColor(WHITE, " \"ax^2 + bx + с = 0\":\n");

    int correct_input_coeff = 0;

    for (int i = 0; i < DEGREE; i++)
    {
        if (correct_input_coeff == 1) break;

        correct_input_coeff = InputOneCoeff(&coeffs[i], &corr_num[i], i);
    }

    return correct_input_coeff;
}

Choise WantToContinue()
{
    while (true)
    {
        char decision = ' ';
        int corr_input_decision = 1;

        printColor(YELLOW, "\n1) Решить новое уравнение");

        printf("   ");

        printColor(WHITE, "2) Выйти из программы\n");

        printf("Введите соответствующий номер: ");

        SET_TEXT_CYAN;
        scanf(" %c", &decision);
        RESET;

        ClearBuffer(&corr_input_decision);

        printf("\n");

        if (decision == '2' and corr_input_decision == 1)
        {
            printColor(WHITE, "Пока-пока!");

            return EXIT;
            break;
        }

        else if (decision == '1' and corr_input_decision == 1)
        {

            return CONTINUE;
            break;
        }

        else
        {

            printColor(RED, "Некорректный номер\n");
        }

    }
}

int InputOneCoeff(double *n, int *corr_input_num, int i)
{
    printf("%c: ", i + 'a');

    SET_TEXT_CYAN;
    *corr_input_num = scanf("%lf", n);
    RESET;

    ClearBuffer(corr_input_num);

    if (*corr_input_num == 0)
    {
        printColor(RED, "Введенный коэффициент %c не является числом", i + 'a');
        return 1;
    }
    else
        return 0;
}


