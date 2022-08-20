#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000001

// 1 - isPrime() 함수 (완전탐색-브루트 포스)
/*
bool isPrime(int num)
{
    if (num == 2)
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}


int main()
{
    int M, N;
    cin >> M;
    cin >> N;

    for (int i = M; i < N; i++)
    {
        if (isPrime(i))
            cout << i << endl;
    }

    return 0;
}
*/

// 2 - 에라토스테네스의 체 방식 이용
/*
bool arr[MAX] = { false, true };  

int main()
{
    int M, N;
    cin >> M >> N;

    // 2의 배수부터 지우기 (소수 = fasle, 그 외 = true)
    for (int i = 2; i <= N; i++)
        for (int j = 2; i * j <= N; j++)
            arr[i * j] = true;

    for (int i = M; i <= N; i++)
        if (!arr[i]) cout << i << '\n';

    return 0;
}
*/

// 3 - 소수와 제곱근 성질 이용
int main()
{
    int M, N;
    cin >> M >> N;

    int max;
    for (int i = M; i <= N; i++)
    {
        bool flag = false;
        max = sqrt(i);   // 제곱근으로 범위를 제한한다.
        if (max == 1 && i != 1)  // 제곱근이 1인 수는 2, 3
            cout << i << '\n';
        else
        {
            for (int j = 2; j <= max; j++)
            {
                if (i % j == 0) break;
                if (j == max) cout << i << '\n';
            }
        }
    }

    return 0;
}