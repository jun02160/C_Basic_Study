#include <iostream>
using namespace std;

// ��ȯ���� �⺻���� �Լ��� ��ȯ���� int �� ���� ���·θ� ������ �� �ִ�. 
int RefRetFuncTwo(int& ref)
{
    ref++;
    return ref;
}

// ��ȯ���� �������� �Լ��� ��ȯ���� int&, int �� ���� ���·� ������ �� �ִ�. 
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