#include <iostream>
using namespace std;

// 반환형이 기본형인 함수는 반환값을 int 한 가지 형태로만 저장할 수 있다. 
int RefRetFuncTwo(int& ref)
{
    ref++;
    return ref;
}

// 반환형이 참조형인 함수는 반환값을 int&, int 두 가지 형태로 저장할 수 있다. 
int& RefRetFunc2(int& ref)
{
    ref++;
    return ref;
}

int main()
{
    int num1 = 1;
    int num2 = RefRetFunc2(num1);
    int num3 = RefRetFuncTwo(num1);

    num1 += 1;
    num2 += 100;
    num3 += 100;

    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    return 0;

}