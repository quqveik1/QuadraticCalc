#pragma once
#include <WindowsLib.h>
#include <LinearLayout.cpp>
#include <DoubleInputButton.cpp>
#include <InputButton2.cpp>
#include <TextView.cpp>
#include <MessageButton.cpp>
#include "Number.h"

struct SolutionWindow : Manager
{
    LinearLayout mainLayout;
    LinearLayout inputLayout;
    DoubleInputButton aButton;
    TextView aView;
    double a = 0;
    DoubleInputButton bButton;
    TextView bView;
    double b = 0;
    DoubleInputButton cButton;
    double c = 0;

    MessageButton calcButton;
    const char* solute = "solute";

    TextView solutions;

    TextView textWindow;

    double minLimit = -100;
    double maxLimit = 100;

    SolutionWindow(AbstractAppData* _app, Vector _size) :
        Manager(_app),
        mainLayout(app, {}, LinearLayout::FLAG_VERTICAL),
        inputLayout(app, {}, LinearLayout::FLAG_HORIZONTAL),
        aButton(app, {}, &a, &minLimit, &maxLimit, DoubleInputButton::STANDART_MODE, app->systemSettings->MenuColor),
        bButton(app, {}, &b, &minLimit, &maxLimit, DoubleInputButton::STANDART_MODE, app->systemSettings->MenuColor),
        cButton(app, {}, &c, &minLimit, &maxLimit, DoubleInputButton::STANDART_MODE, app->systemSettings->MenuColor),
        aView (app, 0, "x^2 + "),
        bView (app, 0, "x + "),
        calcButton(app),
        solutions(app),
        textWindow(app, app->systemSettings->MainFont * 3)
    {
        resize(_size);
        addWindow(mainLayout);
        textWindow.setText("Введите коэффициенты уравнения:");
        textWindow.setWrapStatusY(1);
        mainLayout.addWindow(textWindow);
        mainLayout.addWindow(inputLayout);
        inputLayout.addWindow(aButton);
        inputLayout.addWindow(aView);
        inputLayout.addWindow(bButton);
        inputLayout.addWindow(bView);
        inputLayout.addWindow(cButton);
        calcButton.setReciever(this);
        calcButton.setMessage(solute, NULL);
        mainLayout.addWindow(calcButton);
        mainLayout.addWindow(solutions);
    }

    void setAnswer(Number answers[2], int length);

    virtual int onSize(Vector managerSize, Rect newRect = {});
    virtual void onMessageRecieve(const char* name, void* data) override;
};