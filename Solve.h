#pragma once
#include <array>
#include "Number.h"
#include <Double comparision.h>

using namespace std;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup SolutionSystem
//! @brief   Решает линейное уравнения с заданными коэффициентами ax + bx =0
//!
//! @param   a                Коэффициент a
//! @param   b                Коэффициент b
//!
//! @return  Ответ в виде Number
//!
//! @see     Number
//!
//! @usage @code
//! ...
//! Number answer = solveLinearExpression(b, c);;
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

Number solveLinearExpression(const Number& a, const Number& b)
{
    Number answer = {};
    if (!isEqual(a.num, 0))
    {
        answer.num = -(b.num / a.num);
    }
    else
    {
        printf("Деление на ноль!\n");
    }

    return answer;
}

//! @ingroup SolutionSystem
//! @brief   Решает квадратные уравнения с заданными коэффициентами ax^2 + bx + c =0
//!
//! @param   a                Коэффициент a
//! @param   b                Коэффициент b
//! @param   c                Коэффициент c
//! @param   answer[2]        Массив, куда будут записаны ответы
//!
//! @return  Количество корней или -1 если уравнение некорректное
//!
//! @see     Number, solveLinearExpression
//!
//! @usage @code
//! ...
//! Number na, nb, nc;
//! na.num = a;
//! nb.num = b;
//! nc.num = c;
//! Number answer[2] = {};
//! int answersNum = solveExpression(na, nb, nc, answer);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
int solveExpression(const Number& a, const Number& b, const Number& c, Number answer[2])//ax^2 + bx + c
{
    Number d = {};
    d.num = (b.num * b.num) - (4 * a.num * c.num);
    if (isSmaller(d.num, 0))
    {
        return 0;
    }
    if (isEqual(a.num, 0))
    {
        if (!isEqual(b.num, 0))
        {
            //linear expression
            answer[0] = solveLinearExpression(b, c);
            return 1;
        }
        return -1;
    }

    if (isEqual(d.num, 0))
    {
        //full square case

        answer[0].num = (-b.num) / (2 * a.num);
        return 1;
    }
    else
    {
        Number sqrtD = {};
        sqrtD.num = sqrt(d.num);
        double first = (-b.num - sqrtD.num) / (2 * a.num);
        double second = (-b.num + sqrtD.num) / (2 * a.num);
        answer[0].num = min(first, second);
        answer[1].num = max(first, second);
        return 2;
    }

    return -1;
}
