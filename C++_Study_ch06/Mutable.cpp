#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num1;
    mutable int num2;    // const 함수에 대한 예외를 둔다
public:
    SoSimple(int n1, int n2) :num1(n1), num2(n2)
    { }
    void ShowSimpleData() const
    {
        cout << num1 << ", " << num2 << endl;
    }
    void CopyToNum() const
    {
        num2 = num1;   // const 함수 내에서 num2에 저장된 값을 변경할 수 있다.  by mutable 선언
    }
};

int main()
{
    SoSimple sm(1, 2);
    sm.ShowSimpleData();
    sm.CopyToNum();
    sm.ShowSimpleData();

    return 0;
}