#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base Constructor" << endl; }
    void SimpleFunc() { cout << "BaseOne" << endl; }
};

class MiddleDerivedOne :virtual public Base   // 가상 상속
{
public:
    MiddleDerivedOne() :Base()   // 기초 클래스의 생성자 호출을 명시하지 않아도 기본적으로 호출된다. (없어도 같은 결과)
    {
        cout << "MiddleDerivedOne Constructor" << endl;
    }
    void MiddleFuncOne()
    {
        SimpleFunc();
        cout << "MiddleDerivedOne" << endl;
    }
};

class MiddleDerivedTwo :virtual public Base
{
public:
    MiddleDerivedTwo() :Base()
    {
        cout << "MiddleDerivedTwo Constructor" << endl;
    }
    void MiddleFuncTwo()
    {
        SimpleFunc();
        cout << "MiddleDerivedTwo" << endl;
    }
};

class LastDerived :public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
    LastDerived() :MiddleDerivedOne(), MiddleDerivedTwo()
    {
        cout << "LastDerived Constructor" << endl;
    }
    void ComplexFunc()
    {
        MiddleFuncOne();
        MiddleFuncTwo();
        SimpleFunc();
    }
};

int main()
{
    cout << "객체생성 전 ....." << endl;
    LastDerived ldr;
    cout << "객체생성 후 ....." << endl;
    ldr.ComplexFunc();
    return 0;
}