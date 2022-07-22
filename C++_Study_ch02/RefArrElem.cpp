#include <iostream>
using namespace std;

int main()
{
    int arr[3] = { 1, 3, 5 };
    // 참조자는 반드시 선언과 동시에 변수를 참조해야 함
    int& ref1 = arr[0];
    int& ref2 = arr[1];
    int& ref3 = arr[2];

    cout << ref1 << endl;
    cout << ref2 << endl;
    cout << ref3 << endl;

    return 0;
}