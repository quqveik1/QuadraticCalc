#pragma once
#include "SolutionWindow.h"
#include "Number.cpp"
#include "Solve.h"

int SolutionWindow::onSize(Vector managerSize, Rect newRect /*= {}*/)
{
    
    double xSize = getSize().x;
    double inputButtonSize = (xSize) * ((double)5 / (double)19);
    double viewSize = (xSize) * ((double)2 / (double)19);
    aView.onSize(getSize(), { .pos = {}, .finishPos = {viewSize, getSize().y * 0.3} });
    aView.setFont(app->systemSettings->MainFont * 2);
    bView.onSize(getSize(), { .pos = {}, .finishPos = {viewSize, getSize().y * 0.3} });
    bView.setFont(app->systemSettings->MainFont * 2);
    aButton.onSize(getSize(), { .pos = {}, .finishPos = {inputButtonSize, getSize().y * 0.3} });
    bButton.onSize(getSize(), { .pos = {}, .finishPos = {inputButtonSize, getSize().y * 0.3} });
    cButton.onSize(getSize(), { .pos = {}, .finishPos = {inputButtonSize, getSize().y * 0.3} });
    calcButton.setFont(app->systemSettings->MainFont * 2);
    calcButton.setText("Решить");
    calcButton.onSize(getSize(), { .pos = {}, .finishPos = {getSize().x, getSize().y * 0.3} });
    Manager::onSize(managerSize, newRect);
    return 1;
}




void SolutionWindow::onMessageRecieve(const char* name, void* data)
{
    if (name)
    {
        if (strcmp(name, solute) == 0)
        {
            Number na, nb, nc;
            na.num = a;
            nb.num = b;
            nc.num = c;
            Number answer[2] = {};
            int answersNum = solveExpression(na, nb, nc, answer);
            setAnswer(answer, answersNum);
        }

    }

}


void SolutionWindow::setAnswer(Number answers[2], int length)
{
    printf("Количество решений: %d\n", length);


    solutions.setFont(app->systemSettings->MainFont * 2);
    solutions.onSize(getSize(), { .pos = {}, .finishPos = {getSize().x, getSize().y * 0.3} });
    onSize({}, {});
    if (length == -1)
    {
        solutions.setText("Ошибка");
        return;
    }
    if (length == 0)
    {
        solutions.setText("Нет решений");
    }

    static char strAnswers[MAX_PATH] = {};
    (void)sprintf(strAnswers, "Ответы: ");
    for (int i = 0; i < length; i++)
    {
        (void)sprintf(strAnswers, "%s%d: %s   ", strAnswers, i + 1, answers[i].toString());
    }

    solutions.setText(strAnswers);

}