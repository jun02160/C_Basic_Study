#include <iostream>
using namespace std;

class Point
{
public:
    // ��� �׸��� �⺻���� �Ǵ� ���� ��ǥ (����: 0~100)
    int x;
    int y;
};

class Rectangle
{
public:
    // Rectangle Ŭ������ �������
    Point upLeft;
    Point lowRight;

public:
    // Rectangle Ŭ������ ����Լ�(�޼ҵ�)
    void ShowRecInfo()
    {
        cout << "�� ���: " << '[' << upLeft.x << ", ";
        cout << upLeft.y << ']' << endl;
        cout << "�� �ϴ�: " << '[' << lowRight.x << ", ";
        cout << lowRight.y << ']' << endl << endl;
    }
};

int main()
{
    // ��� ������ public���� �����ϸ� ����ü ���� �ʱ�ȭ�� ������ ������� �ʱ�ȭ�� �� �ִ�. 
    Point pos1 = { -2, 4 };
    Point pos2 = { 5, 9 };
    Rectangle rec = { pos2, pos1 }; 
    rec.ShowRecInfo();
    return 0;
}