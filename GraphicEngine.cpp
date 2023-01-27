#pragma once
#include "GraphicEngine.h"
#include "AbstractApp.cpp"
#include "MainWindow.cpp"
#include <LinearLayout.cpp>
#include <InputButton2.cpp>
#include "MainLayout.cpp"
#include <TextView.cpp>
#include "SolutionWindow.cpp"
#include <DoubleInputButton.cpp>


GraphicEngine::GraphicEngine() :
    AbstractAppData(NULL)
{

}


void GraphicEngine::onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    MainWindow* _mainManager = new MainWindow(this);
    setMainManager(_mainManager);
    MainLayout* inputLayout = new MainLayout(this);
    _mainManager->addWindow(inputLayout);
    //TextView* textWindow = new TextView(this, systemSettings->MainFont * 3);
    //textWindow->setText("Введите коэффициенты уравнения:");
    //textWindow->setWrapStatus(1);
    //textWindow->setMatchParentX(1);
    //inputLayout->addWindow(textWindow);
    
    SolutionWindow* solutionWindow = new SolutionWindow(this, {1000, 255});
    inputLayout->addWindow(solutionWindow);
    
}