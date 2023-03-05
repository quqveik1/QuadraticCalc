// QuadraticCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#define _HAS_STD_BYTE 0
#include <iostream>

#include "GraphicEngine.cpp"


//-----------------------------------------------------------------------------------------------------------------
//! @mainpage QudraticCalc - Простая программа для решения квадратных уравнений в удобном графическом UI.
//!           UI основан на Api(https://github.com/quqveik1/TESTWIN32_GRAPHICAPP), само Api основано на WIN32 GDI.
//! 
//!           В проекте присутсвует проверка решающей системы при помощи юниттестов. 
//!           
//!           В случае если вы решите собрать приложение самостоятельно, НЕОБХОДИМО скачать все файлы из Api (https://github.com/quqveik1/TESTWIN32_GRAPHICAPP) и подключить папку с Api к приложению в линкере.
//!           Проще просто скачать приложение по ссылке https://github.com/quqveik1/QuadraticCalc/releases/latest.
//! 
//!          UI приложения выглядит вот так:
//! 
//!          \image html "C:\Users\Алехандро\Desktop\AlexProjects\QuadraticCalc\Resources\ApplicationExample.png"
//! 
//=================================================================================================================

//-----------------------------------------------------------------------------------------------------------------
//!
//! @defgroup SolutionSystem     Решающая система
//! @defgroup UI                 Графическая часть
//! @defgroup UnitTest           Тестировочная часть
//}
//=================================================================================================================

void input(Number& a, Number& b, Number& c)
{
    printf("Пожалуйста введите коэфиценты уравнения: \n");
    printf("ax^2 + bx + c = 0, сначала а, затем b, затем c\n");
    printf("a: ");
    (void)scanf("%lf", &a.num);

    printf("b: ");
    (void)scanf("%lf", &b.num);

    printf("c: ");
    (void)scanf("%lf", &c.num);
}


//{----------------------------------------------------------------------------------------------------------------
//! @ingroup UnitTest
//! @brief   Дельта сравнения ответов в юнитестах
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
const double unitTestCmpDelta = 0.001;


//{----------------------------------------------------------------------------------------------------------------
//! @ingroup UnitTest
//! @brief   Тестирует уравнение с заданными коэффициентами ax^2 + bx + c =0
//!
//! @param   _a                Коэффициент a
//! @param   _b                Коэффициент b
//! @param   _c                Коэффициент c
//! @param   solutionsAmount   Количество решений
//! @param   firstAnswer       Первый ответ(по умолчанию ноль)
//! @param   secondAnswer      Второй ответ(по умолчанию ноль)
//!
//! @return  1 - юниттест пройден, 0 - юниттест не пройден
//!
//! @see     runAndPrintUnitTest()
//!
//! @usage @code
//!          bool isCorrect = unitTest(_a, _b, _c, solutionsAmount, firstAnswer, secondAnswer);
//!          if (isCorrect)
//!          {
//!             printf("(%lf, %lf, %lf) - юнитест пройден\n", _a, _b, _c);
//!         }
//!         else
//!         {
//!             printf("(%lf, %lf, %lf) - юнитест НЕ пройден\n", _a, _b, _c);
//!         }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool unitTest(double _a, double _b, double _c, int solutionsAmount, double firstAnswer = 0, double secondAnswer = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup UnitTest
//! @brief   Тестирует уравнение и ВЫВОДИТ на экран результат теста с заданными коэффициентами ax^2 + bx + c =0
//!
//! @param   _a                Коэффициент a
//! @param   _b                Коэффициент b
//! @param   _c                Коэффициент c
//! @param   solutionsAmount   Количество решений
//! @param   firstAnswer       Первый ответ(по умолчанию ноль)
//! @param   secondAnswer      Второй ответ(по умолчанию ноль)
//!
//!
//! @see     unitTest()
//!
//! @usage @code
//!    //                                      sol amount
//!    //                   a       b       c       |       first sol       second sol
//!    //полные уравнения
//!    runAndPrintUnitTest (-3.5,   5,      9,      2,      -1.04117,       2.46974);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

void runAndPrintUnitTest(double _a, double _b, double _c, int solutionsAmount, double firstAnswer = 0, double secondAnswer = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup UnitTest
//! @brief   Запускает юниттесты
//}----------------------------------------------------------------------------------------------------------------
void startUnitTest();

int main()
{
    GraphicEngine* graphicEngine = new GraphicEngine();
    //startUnitTest(); <-- Данная функция проводит юнитесты. 
    graphicEngine->startApp();

    delete graphicEngine;
    


    return 0;
}


void startUnitTest()
{
    //                                      sol amount
    //                   a       b       c       |       first sol       second sol
    //полные уравнения
    runAndPrintUnitTest (-3.5,   5,      9,      2,      -1.04117,       2.46974);
    runAndPrintUnitTest (1,      239,    1329,   2,      -233.30356,    -5.69644);
    runAndPrintUnitTest (1,      179,    1589,   2,      -169.6327,     -9.3673);
    runAndPrintUnitTest (1,      5,      9,      0);
    runAndPrintUnitTest (-2,     8,      5,      2,      -0.54951,      4.54951);
    runAndPrintUnitTest (88,     -91,    6,      2,      0.0707785,     0.963312);


    //                   a       b       c       |       first sol       second sol
    //уравнения без c
    runAndPrintUnitTest (8,      57,     0,      2,      -7.125,         0);
    runAndPrintUnitTest (88,     99,     0,      2,      -1.125,         0);
    runAndPrintUnitTest (-57,    99,     0,      2,      1.73684,        0);
    runAndPrintUnitTest (-1,     2,      0,      2,      2,              0);
    runAndPrintUnitTest (32,     63,     0,      2,      -1.96875,       0);
    runAndPrintUnitTest (0,      1,      0,      1,      0);
    

    //                   a       b       c       |       first sol       second sol
    //уравнения без b
    runAndPrintUnitTest (5.8,    0,      -1589,  2,      -16.5519,       16.5519);
    runAndPrintUnitTest (1.329,  0,      -2007,  2,      -38.86075,      38.86075);
    runAndPrintUnitTest (88,     0,      -68,    2,      -0.879049,      0.879049);
    runAndPrintUnitTest (13,     0,      -29,    2,      -1.49358,       1.49358);
    runAndPrintUnitTest (-103,   0,      99,     2,      -0.98039,       0.98039);
    runAndPrintUnitTest (-239,   0,      1547,   2,      -2.54417,       2.54417);
    runAndPrintUnitTest (1.329,  0,      -2007,  2,      -38.86075,      38.86075);
    runAndPrintUnitTest (1.329,  0,      2007,   0);


    //                   a       b       c       |       first sol       second sol
    //уравнения без a
    runAndPrintUnitTest (0,      83,     -68,    1,      0.819277);
    runAndPrintUnitTest (0,      83,     34,     1,      -0.409639);
    runAndPrintUnitTest (0,      1011,   5783,   1,      -5.72008);
    runAndPrintUnitTest (0,      -77,    23,     1,      0.298701);
    runAndPrintUnitTest (0,      -79,    -79,    1,      -1);
    runAndPrintUnitTest (0,      79,     79,     1,      -1); 


    //                   a       b       c       |       first sol       second sol
    //уравнения без а и с
    runAndPrintUnitTest (0,      79,     0,      1,      0);
    runAndPrintUnitTest (0,      -79,    0,      1,      0);
    runAndPrintUnitTest (0,      1.82,   0,      1,      0);
    runAndPrintUnitTest (0,      13.64,  0,      1,      0);
    runAndPrintUnitTest (0,      -83.65, 0,      1,      0);


    //                   a       b       c       |       first sol       second sol
    //уравнения без с и b
    runAndPrintUnitTest (87,     0,      0,      1,      0);
    runAndPrintUnitTest (1329,   0,      0,      1,      0);
    runAndPrintUnitTest (-64,    0,      0,      1,      0);
    runAndPrintUnitTest (22,     0,      0,      1,      0);


    //                   a       b       c       |       first sol       second sol
    //нет коэфициентов
    runAndPrintUnitTest (0,      0,      0,      -1);

    //                   a       b       c       |       first sol       second sol
    //только c
    runAndPrintUnitTest (0,      0,      1,      -1);
    runAndPrintUnitTest (0,      0,      101,    -1);
    runAndPrintUnitTest (0,      0,      55.6,   -1);
}



void runAndPrintUnitTest(double _a, double _b, double _c, int solutionsAmount, double firstAnswer/* = 0*/, double secondAnswer/* = 0*/)
{
    bool isCorrect = unitTest(_a, _b, _c, solutionsAmount, firstAnswer, secondAnswer);
    if (isCorrect)
    {
        printf("(%lf, %lf, %lf) - юнитест пройден\n", _a, _b, _c);
    }
    else
    {
        printf("(%lf, %lf, %lf) - юнитест НЕ пройден\n", _a, _b, _c);
    }
}



bool unitTest(double _a, double _b, double _c, int solutionsAmount, double firstAnswer/* = 0*/, double secondAnswer/* = 0*/)
{
    Number a, b, c;
    a.num = _a;
    b.num = _b;
    c.num = _c;

    Number solutions[2] = {};
    int length = solveExpression(a, b, c, solutions);
    bool isCorrect = true;
    if (length != solutionsAmount)
    {
        isCorrect = false;
        return isCorrect;
    }

    if (isBigger(solutions[0].num, solutions[1].num))
    {
        double copy = solutions[0].num;
        solutions[0].num = solutions[1].num;
        solutions[1].num = copy;
    }

    double answer[2] = { min(firstAnswer, secondAnswer), max(firstAnswer, secondAnswer) };

    for (int i = 0; i < 2; i++)
    { 
        if (!isEqual(solutions[i].num, answer[i], unitTestCmpDelta))
        {
            isCorrect = false;
            return isCorrect;
            
        }
    }

    

    return isCorrect;

}

