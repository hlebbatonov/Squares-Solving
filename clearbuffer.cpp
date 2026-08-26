#include "clearbuffer.h"

// TODO: corr_input_num as return value
void ClearBuffer(int *corr_input_num)
{
    int sym = 0;
    // TODO: set to 1
    while ((sym = getchar()) != '\n')
    {
        *corr_input_num = 0;
    }
}
