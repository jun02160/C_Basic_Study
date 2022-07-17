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

int val1 = 10;   // 전역변수

int main()
{
    AAA::BBB::CCC::num1 = 20;
    AAA::BBB::CCC::num2 = 30;
    int val1 = 20;   // 지역변수


    // 위 코드와 같은 이름공간 중첩 코드의 복잡함을 해결하기 위해 "이름공간 별칭"을 지정
    namespace ABC = AAA::BBB::CCC;
    
    cout << ABC::num1 << endl;
    cout << ABC::num2 << endl;

    // 지역변수와 전역변수명이 같을 때, 지역변수의 범위 내에서 전역변수에 접근하려면 '::'범위지정 연산자를 이용한다. 
    val1 += 3;   // 23
    ::val1 += 10;   // 20
    cout << val1 << endl;
    cout << ::val1 << endl;

    return 0;
}