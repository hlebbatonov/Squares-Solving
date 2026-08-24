#include "clearbuffer.h"

void ClearBuffer(int *corr_input_num)
{
    int sym = ' ';
    while ((sym = getchar()) != '\n')
    {
        *corr_input_num = 0;
    }
}
