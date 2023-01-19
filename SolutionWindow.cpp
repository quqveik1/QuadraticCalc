#pragma once
#include "SolutionWindow.h"
#include "Number.cpp"
#include "Solve.h"

int SolutionWindow::onSize(Vector managerSize, Rect newRect /*= {}*/)
{
    //aView.setHeight(getSize().y);
    //bView.setHeight(getSize().y);
    double xSize = getSize().x;
    double inputButtonSize = (xSize - aView.getSize().x - bView.getSize().x) * ((double)5 / (double)19);
    aButton.onSize(getSize(), { .pos = {}, .finishPos = {inputButtonSize, getSize().y * 0.5} });
    bButton.onSize(getSize(), { .pos = {}, .finishPos = {inputButtonSize, getSize().y * 0.5} });
    cButton.onSize(getSize(), { .pos = {}, .finishPos = {inputButtonSize, getSize().y * 0.5} });
    calcButton.setFont(app->systemSettings->MainFont);
    calcButton.setText("Поехали");
    calcButton.setWrapStatus(1);
    calcButton.setWrapStatus(1);
    Manager::onSize(managerSize, newRect);
    return 1;
}




void SolutionWindow::onMessageRecieve(const char* name, void* data)
{
    if (name)
    {
        if (strcmp(name, solute) == 0)
        {
            Number a, b, c;
        }

    }

}