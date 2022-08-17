#include <iostream>
using namespace std;

class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) :width(w), height(h)
    { }
    void ShowAreaInfo()
    {
        int area = width * height;
        cout << "�簢���� ������ " << area << " �Դϴ�." << endl;
    }
};

class Square :public Rectangle
{
public:
    Square(int n) :Rectangle(n, n)
    {
        //empty
    }
};

int main()
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}