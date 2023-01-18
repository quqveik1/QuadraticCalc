#pragma once
#include <Manager.h>

struct MainWindow : Manager
{
    MainWindow(AbstractAppData* _app) :
        Manager(_app)
    {
    }

    virtual int onSize(Vector managerSize, Rect _newRect = {}) override;
};