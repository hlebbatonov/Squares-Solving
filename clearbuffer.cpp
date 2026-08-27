#include "clearbuffer.h"
int ClearBuffer()
{
    int sym = 0;
    int corr_input_num = 1;
    while ((sym = getchar()) != '\n')
    {
        corr_input_num = 0;
    }
    return corr_input_num;
}
