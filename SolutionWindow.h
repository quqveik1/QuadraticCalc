#pragma once
#include <WindowsLib.h>
#include <LinearLayout.cpp>
#include <DoubleInputButton.cpp>
#include <TextView.cpp>

struct SolutionWindow : Manager
{
    LinearLayout mainLayout;
    DoubleInputButton aButton;
    TextView aView;
    double a = 0;
    DoubleInputButton bButton;
    TextView bView;
    double b = 0;
    DoubleInputButton cButton;
    TextView cView;
    double c = 0;

    double minLimit = -100;
    double maxLimit = 100;

    SolutionWindow(AbstractAppData* _app, Vector _size) :
        Manager(_app),
        mainLayout(app, {}, LinearLayout::FLAG_HORIZONTAL),
        aButton(app, { .pos = {}, .finishPos = {getSize().x  * (5 / 19), getSize().y} }, &a, &minLimit, &maxLimit, 0, C_RED),
        bButton(app, { .pos = {}, .finishPos = {getSize().x  * (5 / 19), getSize().y} }, &b, &minLimit, &maxLimit, 0, C_RED),
        cButton(app, { .pos = {}, .finishPos = {getSize().x  * (5 / 19), getSize().y} }, &c, &minLimit, &maxLimit, 0, C_RED),
        aView (app, getSize().y * 0.9, "x^2"),
        bView (app, getSize().y * 0.9, "x^2"),
        cView (app, getSize().y * 0.9, "x^2")
    {
        resize(_size);
        addWindow(mainLayout);
        mainLayout.addWindow(aButton);
        mainLayout.addWindow(aView);
        mainLayout.addWindow(bButton);
        mainLayout.addWindow(bView);
        mainLayout.addWindow(cButton);
        mainLayout.addWindow(cView);

    }
};