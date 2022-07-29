#include <iostream>
#include "Circle.h"

using namespace std;

int Circle::GetMidX() const
{
    return mid.GetX();
}

int Circle::GetMidY() const
{
    return mid.GetY();
}

int Circle::GetRad() const
{
    return radius;
}

bool Circle::Init(const Point& m, const int& r)
{
    mid = m;
    radius = r;

    return true;
}

void Circle::ShowCircleInfo() const
{
    cout << "radius: " << radius << endl;
    mid.ShowPointInfo();
}