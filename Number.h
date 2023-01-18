#pragma once



struct Number
{
    double num;
    static const int stringNumberSize = 200;

    const char* toString();
};