#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Ring.h"

int main()
{
    Ring ring;
    Circle c1, c2;
    Point m1, m2;
    m1.InitMembers(1, 1);
    m2.InitMembers(2, 2);
    c1.Init(m1, 4);
    c2.Init(m2, 9);

    ring.InitMembers(c1, c2);
    ring.ShowTotalInfo();
    return 0;
}