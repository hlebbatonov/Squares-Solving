#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>

#define HEAD        "Программа для решения квадратных уравнений version"
#define VERSION     "1.8"
#define ACCURACY    10e-5
#define DEGREE      3

#define SET_TEXT_RED       txSetConsoleAttr(FOREGROUND_LIGHTRED)
#define SET_TEXT_GREEN     txSetConsoleAttr(FOREGROUND_LIGHTGREEN)
#define SET_TEXT_YELLOW    txSetConsoleAttr(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define SET_TEXT_BLUE      txSetConsoleAttr(FOREGROUND_LIGHTBLUE)
#define SET_TEXT_CYAN      txSetConsoleAttr(FOREGROUND_LIGHTCYAN)
#define SET_TEXT_WHITE     txSetConsoleAttr(FOREGROUND_WHITE)
#define SET_TEXT_PURPLE    txSetConsoleAttr(FOREGROUND_MAGENTA)

#define SET_BG_RED         txSetConsoleAttr(BACKGROUND_RED | FOREGROUND_WHITE)
#define SET_BG_BLUE        txSetConsoleAttr(BACKGROUND_BLUE | FOREGROUND_WHITE)
#define SET_BG_GREEN       txSetConsoleAttr(BACKGROUND_GREEN | FOREGROUND_BLACK)
#define SET_BG_WHITE       txSetConsoleAttr(BACKGROUND_WHITE | FOREGROUND_BLACK)

#define RESET              txSetConsoleAttr(FOREGROUND_LIGHTGRAY)


struct TestKeys
{
    double a, b, c;
    int number_of_roots_ref;
    double x1_ref, x2_ref;
};

enum Roots
{
    INF = -1,
    ZERO,
    ONE,
    TWO
};

enum Colors
{
    WHITE,
    GREEN,
    RED,
    CYAN,
    BG_WHITE,
    YELLOW
};

enum Choise
{
    CONTINUE = 0,
    EXIT = 1,
};

Roots   SolveEquation           (double coeffs[], double *x1, double *x2);

int     IsEqual                 (double a, double b);

void    OutputRoots             (int number_of_roots, double x1, double x2);

int     InputAllCoeffs          (double coeffs[]);

double  CalculateDiscriminant   (double a, double b, double c);

Roots   SolveLinear             (double coeffs[], double *x1);

Roots   SolveSquare             (double coeffs[], double *x1, double *x2);

double  RoundDoubleToZero       (double fraction);

void    HandleWithOneEquation   ();

Choise  WantToContinue          ();

void    ClearBuffer             (int *corr_input_num);

int     InputOneCoeff           (double *n, int *corr_input_num, int i);

void    printColor              (Colors color, const char str[], ...);

void    switchColor             (Colors color);

#endif



