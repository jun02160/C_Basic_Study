#include <iostream>
// 각각의 함수에 대한 using 선언
using std::cin;
using std::cout;
using std::endl;

// 이름공간 전체에 대한 using 선언 -> 해당 이름공간 내 모든 함수를 이름공간 없이 단독으로 호출할 수 있다. 
using namespace std;    // 모든 코드에 표준 입출력을 위한 선언을 추가하는 것이 좋은 습관이다.

int main()
{
    int num = 20;
    cout << "Hello World" << endl;
    cout << "Hello" << " World" << endl;

    return 0;
}