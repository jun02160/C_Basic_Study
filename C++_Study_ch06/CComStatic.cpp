#include <iostream>
using namespace std;

void Counter()
{
    static int cnt;    // static 변수는 전역변수와 마찬가지로 따로 명시되지 않으면 기본 초기화 값이 0으로 설정된다. 
    cnt++;
    cout << "Current cnt : " << cnt << endl;
}

int main()
{
    for (int i = 0; i < 10; i++)
        Counter();
    return 0;
}