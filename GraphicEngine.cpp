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
    setMinSize(SOLUTIONWINDOWSIZE + 50);
}


void GraphicEngine::onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
    MainWindow* _mainManager = new MainWindow(this);
    setMainManager(_mainManager);
    MainLayout* inputLayout = new MainLayout(this);
    _mainManager->addWindow(inputLayout);
    
    SolutionWindow* solutionWindow = new SolutionWindow(this, SOLUTIONWINDOWSIZE);
    inputLayout->addWindow(solutionWindow);
    
}