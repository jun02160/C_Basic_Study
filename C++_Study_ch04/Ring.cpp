#include <iostream>
#include "Ring.h"

using namespace std;

bool Ring::InitMembers(const Circle& in, const Circle& out)
{
    if (in.GetMidX() == out.GetMidX() && in.GetMidY() == out.GetMidY())
    {
        cout << "�β��� ������ ��" << endl;
        if (in.GetRad() > out.GetRad())
        {
            cout << "�߸��� �����Դϴ�" << endl;
            inner = out;
            outer = in;
            return true;
        }
    }
    else if (in.GetRad() > out.GetRad())
    {
        cout << "�β��� ������ ��" << endl;
        cout << "�߸��� �����Դϴ�" << endl;
        return false;
    }

    cout << "�β��� ������ ��" << endl;
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
