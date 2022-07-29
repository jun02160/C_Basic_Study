#pragma once
#ifndef __RECTANGLE__H_
#define __RECTANGLE__H_

#include "Point.h"

class Rectangle
{
private:
    Point upLeft;
    Point lowRight;
public:
    bool InitMembers(const Point& ul, const Point& lr);
    void ShowRecInfo() const;

    // 생성자 추가
    Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
};

#endif