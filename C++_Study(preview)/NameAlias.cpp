#include <iostream>
using namespace std;

namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }
    }
}

int val1 = 10;   // ��������

int main()
{
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;
    int val1 = 20;   // ��������


    // �� �ڵ�� ���� �̸����� ��ø �ڵ��� �������� �ذ��ϱ� ���� "�̸����� ��Ī"�� ����
    namespace ABC = AAA::BBB::CCC;
    
    cout << ABC::num1 << endl;
    cout << ABC::num2 << endl;

    // ���������� ������������ ���� ��, ���������� ���� ������ ���������� �����Ϸ��� '::'�������� �����ڸ� �̿��Ѵ�. 
    val1 += 3;   // 23
    ::val1 += 10;   // 20
    cout << val1 << endl;
    cout << ::val1 << endl;

    return 0;
}