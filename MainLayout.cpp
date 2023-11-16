#pragma once
#include "MainLayout.h"


int MainLayout::onSize(Vector managerSize, Rect _newRect/* = {}*/)
{
    LinearLayout::onSize(getSize());
    Vector locSize = getSize();
    Vector newPos = app->getCentrizedPos(locSize, managerSize);
    MoveWindowTo(newPos, false);
    return 0;
}
