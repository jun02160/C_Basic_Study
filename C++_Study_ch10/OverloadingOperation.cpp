#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) :xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point operator+(const Point& ref)   // 함수명 : operator+ 
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);   // 객체를 통한 덧셈 연산
        return pos;
    }
};

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1 + pos2;  // = pos1.operator + (pos2) 으로 자동 변환하여 수행

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}