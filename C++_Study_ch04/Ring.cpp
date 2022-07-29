#include <iostream>
#include "Ring.h"

using namespace std;

bool Ring::InitMembers(const Circle& in, const Circle& out)
{
    if (in.GetMidX() == out.GetMidX() && in.GetMidY() == out.GetMidY())
    {
        cout << "두께가 일정한 원" << endl;
        if (in.GetRad() > out.GetRad())
        {
            cout << "잘못된 정보입니다" << endl;
            inner = out;
            outer = in;
            return true;
        }
    }
    else if (in.GetRad() > out.GetRad())
    {
        cout << "두께가 상이한 원" << endl;
        cout << "잘못된 정보입니다" << endl;
        return false;
    }

    cout << "두께가 상이한 원" << endl;
    inner = in;
    outer = out;
    return true;
}

void Ring::ShowTotalInfo() const
{
    cout << "Inner Circle Info..." << endl;
    inner.ShowCircleInfo();
    cout << "Outer Circle Info..." << endl;
    outer.ShowCircleInfo();
}
