#include "colorprinting.h"



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

