#pragma once
#include "GraphicEngine.h"
#include "AbstractApp.cpp"


GraphicEngine::GraphicEngine() :
    AbstractAppData(NULL)
{
    setWindowParameters(hInstance);
}