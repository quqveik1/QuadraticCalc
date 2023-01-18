#pragma once
#include <LinearLayout.h>

struct MainLayout : LinearLayout
{
    MainLayout(AbstractAppData* _app) :
        LinearLayout(_app, {}, LinearLayout::FLAG_VERTICAL)
    {}

    virtual int onSize(Vector managerSize, Rect _newRect = {}) override;
};