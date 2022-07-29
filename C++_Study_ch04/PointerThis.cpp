#include <iostream>
#include <cstring>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) :num(n)
    {
        cout << "num = " << num << ", ";
        cout << "address = " << this << endl;   // this 포인터의 사용-> 주소값과 자료형이 정해져 있지 않아 그때그때 사용 위치에 따라 달라진다. 
    }
    void ShowSimpleData()
    {
        cout << num << endl;
    }
    SoSimple* GetThisPointer()
    {
        return this;
    }
};

int main()
{
    SoSimple sim1(100);
    SoSimple* ptr1 = sim1.GetThisPointer();   // sim1 객체의 주소값을 저장하는 포인터 변수
    cout << ptr1 << ", ";
    ptr1->ShowSimpleData();

    SoSimple sim2(200);
    SoSimple* ptr2 = sim2.GetThisPointer();
    cout << ptr2 << ", ";
    ptr2->ShowSimpleData();
    return 0;
}