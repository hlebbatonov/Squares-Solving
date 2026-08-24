#include "common.h"
#include "solving.h"
#include "colorprinting.h"
#include "clearbuffer.h"



enum Choise
{
    CONTINUE = 0,
    EXIT = 1,
};

void    OutputRoots             (int number_of_roots, double x1, double x2);

int     InputAllCoeffs          (double coeffs[]);

void    HandleWithOneEquation   ();

Choise  WantToContinue          ();

int     InputOneCoeff           (double *n, int *corr_input_num, int i);




int main()
{

    printColor(BG_WHITE, "%s %s\n\n", HEAD, VERSION);

    while (true)
    {
        HandleWithOneEquation();

        if (WantToContinue() == EXIT) return 0;
    }
}



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



void HandleWithOneEquation()
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





