#include <iostream>
using namespace std;

class Point
{
private:
    int num1, num2;
public:
    Point(int x=0, int y=0) :num1(x), num2(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << num1 << ", " << num2 << "]" << endl;
    }
    // 멤버함수 형태로 오버로딩 : 피연산자의 부호를 반전시키는 연산자 정의
    Point operator- ()
    {
        Point pos(-num1, -num2);
        return pos;
    }
    friend Point operator~ (const Point&);
};

// 전역변수 형태로 오버로딩 : 비트 단위를 서로 반전시키는 연산자 정의
Point operator~(const Point& ref)
{
    Point pos(ref.num2, ref.num1);
    return pos;
}

int main()
{
    Point pos1(9, -7);
    pos1.ShowPosition();
    Point pos2 = -pos1;
    pos2.ShowPosition();

    (~pos2).ShowPosition();
    pos2.ShowPosition();
    return 0;
}