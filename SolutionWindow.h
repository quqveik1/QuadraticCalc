#pragma once
#include <WindowsLib.h>
#include <LinearLayout.cpp>
#include <DoubleInputButton.cpp>
#include <TextView.cpp>
#include <MessageButton.cpp>

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

    double minLimit = -100;
    double maxLimit = 100;

    SolutionWindow(AbstractAppData* _app, Vector _size) :
        Manager(_app),
        mainLayout(app, {}, LinearLayout::FLAG_VERTICAL),
        inputLayout(app, {}, LinearLayout::FLAG_HORIZONTAL),
        aButton(app, {}, &a, &minLimit, &maxLimit, 0, C_RED),
        bButton(app, {}, &b, &minLimit, &maxLimit, 0, C_RED),
        cButton(app, {}, &c, &minLimit, &maxLimit, 0, C_RED),
        aView (app, 0, "x^2 + "),
        bView (app, 0, "x + "),
        calcButton(app)
    {
        resize(_size);
        addWindow(mainLayout);
        mainLayout.addWindow(inputLayout);
        inputLayout.addWindow(aButton);
        inputLayout.addWindow(aView);
        inputLayout.addWindow(bButton);
        inputLayout.addWindow(bView);
        inputLayout.addWindow(cButton);
        calcButton.setReciever(this);
        calcButton.setMessage(solute, NULL);
        mainLayout.addWindow(calcButton);
    }

    virtual int onSize(Vector managerSize, Rect newRect = {});
    virtual void onMessageRecieve(const char* name, void* data) override;
};