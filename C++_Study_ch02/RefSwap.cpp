#include <iostream>
using namespace std;

void SwapByRef(int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

// 참조자를 이용한 call-by-reference
void SwapByRef2(int& ref1, int& ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main()
{
    int val1 = 10;
    int val2 = 20;

    SwapByRef(&val1, &val2);

    cout << val1 << endl;
    cout << val2 << endl;


    SwapByRef2(val1, val2);


    cout << val1 << endl;
    cout << val2 << endl;
    return 0;
}