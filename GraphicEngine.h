#pragma once
#include <AbstractApp.h>

struct GraphicEngine : AbstractAppData
{
    GraphicEngine();

    virtual void onCreate(HWND window, UINT message, WPARAM wParam, LPARAM lParam) override;
};