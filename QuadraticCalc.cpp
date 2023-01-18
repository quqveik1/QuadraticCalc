// QuadraticCalc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#define _HAS_STD_BYTE 0
#include <iostream>
#include "Number.cpp"
#include "Solve.h"
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
    graphicEngine->startApp();


    return 0;
}
