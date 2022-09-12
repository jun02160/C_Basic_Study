#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) :xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << "[" << xpos << ", " << ypos << "]" << endl;
    }
    // 멤버함수의 형태로 오버로딩
    Point& operator++()
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend Point& operator--(Point& ref);
};

// 전역함수의 형태로 오버로딩
Point& operator--(Point& ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main()
{
    Point pos(1, 2);
    ++pos;   // pos.operator++(); 로 해석된다. 
    pos.ShowPosition();
    --pos;   // operator--(pos); 로 해석된다.
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();
    return 0;
}