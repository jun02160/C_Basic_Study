#include <iostream>
using namespace std;

class Point;

class PointOp
{
private:
    int opcnt;
public:
    PointOp() :opcnt(0)
    {}

    // PointOp 클래스의 멤버함수
    Point PointAdd(const Point&, const Point&);
    Point PointSub(const Point&, const Point&);
    ~PointOp()
    {
        cout << "Operation times: " << opcnt << endl;
    }
};

class Point
{
private:
    int x;
    int y;
public:
    Point(const int& xpos, const int& ypos) :x(xpos), y(ypos)
    {

    }
    // PointOp 클래스의 멤버함수에 대한 friend 선언
    friend Point PointOp::PointAdd(const Point&, const Point&);
    friend Point PointOp::PointSub(const Point&, const Point&);
    friend void ShowPointPos(const Point&);   // friend 선언과 동시에 함수원형 선언
};


// Point 클래스의 friend로 선언되었기 때문에 private 멤버에 접근이 가능하다
Point PointOp::PointAdd(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOp::PointSub(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main()
{
    Point pos1(1, 2);
    Point pos2(2, 4);
    PointOp op;

    ShowPointPos(op.PointAdd(pos1, pos2));
    ShowPointPos(op.PointSub(pos1, pos2));
}

void ShowPointPos(const Point& pos)
{
    cout << "x: " << pos.x << ", ";
    cout << "y: " << pos.y << endl;
}