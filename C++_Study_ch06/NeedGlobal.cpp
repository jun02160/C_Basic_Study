#include <iostream>
using namespace std;

// 클래스에서 사용할 전역변수 선언
// 객체들이 공유하는 변수이지만, 클래스마다 구분은 불가능한 상태이다.  => 객체와 변수의 생성, 소멸 시점을 맞춰주는 것이 중요!(클래스 내에서 선언하자)
int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
    SoSimple()
    {
        simObjCnt++;
        cout << simObjCnt << "번째 SoSimple 객체" << endl;
    }
};

class SoComplex
{
public:
    SoComplex()
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
    SoComplex(SoComplex &copy)
    {
        cmxObjCnt++;
        cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
    }
};

int main()
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;
    SoComplex();

    return 0;
}