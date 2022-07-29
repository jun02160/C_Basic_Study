#include <iostream>
using namespace std;

class Point
{
public:
    // 모든 그림의 기본값이 되는 점의 좌표 (범위: 0~100)
    int x;
    int y;
};

class Rectangle
{
public:
    // Rectangle 클래스의 멤버변수
    Point upLeft;
    Point lowRight;

public:
    // Rectangle 클래스의 멤버함수(메소드)
    void ShowRecInfo()
    {
        cout << "좌 상단: " << '[' << upLeft.x << ", ";
        cout << upLeft.y << ']' << endl;
        cout << "우 하단: " << '[' << lowRight.x << ", ";
        cout << lowRight.y << ']' << endl << endl;
    }
};

int main()
{
    // 멤버 변수를 public으로 선언하면 구조체 변수 초기화와 동일한 방식으로 초기화할 수 있다. 
    Point pos1 = { -2, 4 };
    Point pos2 = { 5, 9 };
    Rectangle rec = { pos2, pos1 }; 
    rec.ShowRecInfo();
    return 0;
}