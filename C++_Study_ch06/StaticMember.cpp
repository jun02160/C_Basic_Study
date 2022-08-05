#include <iostream>
using namespace std;

class SoSimple
{
private:
    static int simObjCnt;   // static 멤버변수로 선언함으로써 다른 객체의 접근을 막는다. 
public:
    SoSimple()
    {
        simObjCnt++;
        cout << simObjCnt << "번째 SoSimple 객체" << endl;
    }
};
int SoSimple::simObjCnt = 0;   // static 변수는 생성자에서 초기화하지 않는다 -> 별도로 정의된 static 멤버변수의 초기화 문법

class SoComplex
{
private:
    static int cmxObjCnt;
public:
    SoComplex()
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
    SoComplex(SoComplex& copy)
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
};
int SoComplex::cmxObjCnt = 0;

int main()
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}