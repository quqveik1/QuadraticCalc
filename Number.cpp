#pragma once
#include "Number.h"
#include <stdio.h>


const char* Number::toString()
{
    static char res[stringNumberSize] = {};

    (void)sprintf(res, "%lf", num);
    return res;
}
