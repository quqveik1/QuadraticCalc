// QuadraticCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#define _HAS_STD_BYTE 0
#include <iostream>

#include "GraphicEngine.cpp"

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


const double unitTestCmpDelta = 0.001;

void unitTest(double _a, double _b, double _c, double firstAnswer = 0, double secondAnswer = 0);
void startUnitTest();

int main()
{
    /*
    
    Number a, b, c;
    input(a, b, c);


    Number answer[2] = {};
    int answersNum = solveExpression(a, b, c, answer);
    printf("Количество решений: %d\n", answersNum);

    for (int i = 0; i < answersNum; i++)
    {
        printf("%d: %s\n", i + 1, answer[i].toString());
    }
    */
    
    
    GraphicEngine* graphicEngine = new GraphicEngine();
    startUnitTest();
    graphicEngine->startApp();
    


    return 0;
}


void startUnitTest()
{
    unitTest(-3.5, 5, 9, -1.04117, 2.46974);
    unitTest(1, 5, 9);
    unitTest(8, 57, 0, -7.125);
    unitTest(1, 239, 1329, -233.30356, -5.69644);
    unitTest(1, 179, 1589, -169.6327, -9.3673);
    unitTest(5.8, 0, -1589, -16.5519, 16.5519);
    unitTest(1.329, 0, -2007, -38.86075, 38.86075);
    unitTest(1.329, 0, 2007);
    unitTest(88, 99, 0, -1.125);
    unitTest(-57, 99, 0, 1.73684);
}



void unitTest(double _a, double _b, double _c, double firstAnswer/* = 0*/, double secondAnswer/* = 0*/)
{
    Number a, b, c;
    a.num = _a;
    b.num = _b;
    c.num = _c;

    Number solutions[2] = {};
    int length = solveExpression(a, b, c, solutions);
    bool isCorrect = true;

    double answer[2] = { min(firstAnswer, secondAnswer), max(firstAnswer, secondAnswer) };

    for (int i = 0; i < 2; i++)
    { 
        if (!isEqual(solutions[i].num, answer[i], unitTestCmpDelta))
        {
            isCorrect = false;
            
        }
    }

    if (isCorrect)
    {
        printf("(%lf, %lf, %lf) - юнитест пройден\n", _a, _b, _c);
    } 
    else
    {
        printf("(%lf, %lf, %lf) - юнитест НЕ пройден\n", _a, _b, _c);
    }

}
