#include <iostream>
using namespace std;

class AAA
{
private:
    int num;
public:
    AAA() : num(0) {}
    AAA& CreateInitObj(int n) const
    {
        AAA* ptr = new AAA(n);
        return *ptr;
    }
    void ShowNum() const
    {
        cout << num << endl;
    }
private:
    // private 생성자는 참조자를 통해 참조할 수 있다. 
    AAA(int n) : num(n) {}
};

int main()
{
    AAA base;
    base.ShowNum();

    AAA& obj1 = base.CreateInitObj(3);
    obj1.ShowNum();

    AAA& obj2 = base.CreateInitObj(12);
    obj2.ShowNum();

    delete& obj1;
    delete& obj2;
    return 0;
}