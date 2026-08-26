#ifndef COLORPRINTING_H
#define COLORPRINTING_H


#include "common.h"

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

enum Colors
{
    WHITE,
    GREEN,
    RED,
    CYAN,
    BG_WHITE,
    YELLOW
};

void printColor(Colors color, const char str[], ...);
void switchColor(Colors color);

#endif
