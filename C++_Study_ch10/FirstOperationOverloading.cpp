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
    Point operator+(const Point& ref)   // ÇÔ¼ö¸í : operator+ 
    {
        Point pos(xpos + ref.xpos, ypos + ref.ypos);   // µÎ °´Ã¼ÀÇ ¸â¹öº° µ¡¼À °á°ú·Î »õ·Î¿î °´Ã¼ »ý¼º
        return pos;
    }
};

int main()
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3 = pos1.operator+(pos2);

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;
}