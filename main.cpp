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


Roots SolveEquation(double coeffs[], double *x1, double *x2)
{

    if (IsEqual(coeffs[DEGREE - 3], 0))
        return (SolveLinear(coeffs, x1));

    else
        return (SolveSquare(coeffs, x1, x2));

}

int IsEqual(double a, double b)
{
    return ((fabs(a - b) < ACCURACY) ? 1: 0);
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

double CalculateDiscriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

Roots SolveLinear(double coeffs[], double *x1)
{
    //solve equation: bx + c = 0
    double b = coeffs[DEGREE - 2], c = coeffs[DEGREE - 1];

    if (IsEqual(b, 0))
    {
        if (IsEqual(c, 0))
            return INF;
        else
            return ZERO;
    }

    else
    {
        *x1 = -c / b;
        return ONE;
    }
}

Roots SolveSquare(double coeffs[], double *x1, double *x2)
{
    //solve equation: ax^2 + bx + c = 0
    double a = coeffs[DEGREE - 3], b = coeffs[DEGREE - 2], c = coeffs[DEGREE - 1];

    double discriminant = CalculateDiscriminant(a, b, c);

    double sqrt_discriminant = 0;

    if (discriminant < 0) return ZERO;

    else if (IsEqual(discriminant, 0))
    {
        *x1 = -b / ( 2 * a);
        return ONE;
    }

    else
    {
        sqrt_discriminant = sqrt(discriminant);

        *x1 = (-b + sqrt_discriminant) / (2 * a);
        *x2 = (-b - sqrt_discriminant) / (2 * a);
        return TWO;
    }
}

double RoundDoubleToZero(double fraction)
{
    return ((IsEqual(fraction, 0) ? 0: fraction));
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

void ClearBuffer(int *corr_input_num)
{
    int sym = ' ';
    while ((sym = getchar()) != '\n')
    {
        *corr_input_num = 0;
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

void printColor(Colors color, const char str[], ...)
{
    va_list args;
    va_start(args, str);

    switchColor(color);

    vprintf(str, args);

    va_end(args);
    RESET;
}


void switchColor(Colors color)
{
    switch (color)
    {
        case WHITE:
            SET_TEXT_WHITE;
            break;

        case GREEN:
            SET_TEXT_GREEN;
            break;
        case CYAN:
            SET_TEXT_CYAN;
            break;
        case RED:
            SET_TEXT_RED;
            break;
        case YELLOW:
            SET_TEXT_YELLOW;
            break;
        case BG_WHITE:
            SET_BG_WHITE;
            break;
        default:
            RESET;
            break;
    }
}


