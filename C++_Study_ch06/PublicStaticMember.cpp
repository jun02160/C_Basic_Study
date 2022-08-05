#include <iostream>
using namespace std;

class SoSimple
{
public:
    // static 멤버는 private 으로 선언 시, 해당 클래스에서만 접근이 가능하지만 public 으로 선언 시 어디서든 접근이 가능해진다. 
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt = 0;

int main()
{
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;   // 객체 생성 전에 이미 메모리 공간에 할당되어 있으므로 변수 사용이 가능하다. 
    SoSimple sim1;
    SoSimple sim2;

    // public static 멤버에 접근할 때는 클래스의 이름을 이용해서 접근하는 것이 좋다.  for 클래스 멤버 변수와의 구분
    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;

    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;

    return 0;
}