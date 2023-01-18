#pragma once
#include <array>
#include "Number.h"
#include <Double comparision.h>

using namespace std;


int solveExpression(Number a, Number b, Number c, Number answer[2])//ax^2 + bx + c
{
    Number d = {};
    d.num = (b.num * b.num) - (4 * a.num * c.num);
    if (isSmaller(d.num, 0))
    {
        return 0;
    }
    if (isEqual(d.num, 0))
    {
        answer[0].num = (-b.num) / (2 * a.num);
        return 1;
    }
    else
    {
        Number sqrtD = {};
        sqrtD.num = sqrt(d.num);
        answer[0].num = (-b.num - sqrtD.num) / (2 * a.num);
        answer[1].num = (-b.num + sqrtD.num) / (2 * a.num);
        return 2;
    }

    return -1;
}
//returns amount of solutions


