#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) :num(n)
    {

    }
    SoSimple(SoSimple& copy) :num(copy.num)
    {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    void ShowSimpleData()
    {
        cout << "num: " << num << endl;
    }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowSimpleData();
}

int main()
{
    SoSimple obj(7);
    cout << "함수호출 전" << endl;
    SimpleFuncObj(obj);   // 초기화의 대상은 함수의 매개변수인 ob객체 -> ob 객체의 복사 생성자가 호출되면서, obj 객체가 인자로 전달되어야 한다.
    cout << "함수호출 후" << endl;
    return 0;
}