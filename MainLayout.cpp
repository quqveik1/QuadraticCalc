#pragma once
#include "MainLayout.h"

int MainLayout::onSize(Vector managerSize, Rect _newRect/* = {}*/)
{
    LinearLayout::onSize(getSize());
    Vector locSize = getSize();
    Vector newPos = app->getCentrizedPos(locSize, managerSize);
    rect.pos = newPos;
    rect.finishPos = rect.pos + getSize();
    return 0;

}