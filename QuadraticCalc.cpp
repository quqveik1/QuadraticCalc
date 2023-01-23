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

bool unitTest(double _a, double _b, double _c, int solutionsAmount, double firstAnswer = 0, double secondAnswer = 0);
void runAndPrintUnitTest(double _a, double _b, double _c, int solutionsAmount, double firstAnswer = 0, double secondAnswer = 0);
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
    runAndPrintUnitTest(-3.5, 5, 9, 2, -1.04117, 2.46974);
    runAndPrintUnitTest(1, 5, 9, 0);
    runAndPrintUnitTest(8, 57, 0, 2, -7.125, 0);
    runAndPrintUnitTest(1, 239, 1329, 2, -233.30356, -5.69644);
    runAndPrintUnitTest(1, 179, 1589, 2, -169.6327, -9.3673);
    runAndPrintUnitTest(5.8, 0, -1589, 2, -16.5519, 16.5519);
    runAndPrintUnitTest(1.329, 0, -2007, 2, -38.86075, 38.86075);
    runAndPrintUnitTest(1.329, 0, 2007, 0);
    runAndPrintUnitTest(88, 99, 0, 2, -1.125, 0);
    runAndPrintUnitTest(-57, 99, 0, 2, 1.73684, 0);
    runAndPrintUnitTest(-1, 0, 0, 1);
    runAndPrintUnitTest(0, 0, 0, -1);
    runAndPrintUnitTest(0, 1, 0, 1, 0);
    runAndPrintUnitTest(0, 0, 1, -1);
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

