#include "clearbuffer.h"
int ClearBuffer()
{
    int sym = 0;
    int input_is_correct = 1;

    while ((sym = getchar()) != '\n')
    {
        input_is_correct = 0;
    }
    return input_is_correct;
}
