#pragma once
#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "Point.h"

class Circle
{
private:
    Point mid;
    int radius;
public:
    int GetMidX() const;
    int GetMidY() const;
    int GetRad() const;
    bool Init(const Point& mid, const int& r);
    void ShowCircleInfo() const;
};

#endif