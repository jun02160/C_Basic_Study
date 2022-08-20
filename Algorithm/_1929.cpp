#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000001

// 1 - isPrime() �Լ� (����Ž��-���Ʈ ����)
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

// 2 - �����佺�׳׽��� ü ��� �̿�
/*
bool arr[MAX] = { false, true };  

int main()
{
    int M, N;
    cin >> M >> N;

    // 2�� ������� ����� (�Ҽ� = fasle, �� �� = true)
    for (int i = 2; i <= N; i++)
        for (int j = 2; i * j <= N; j++)
            arr[i * j] = true;

    for (int i = M; i <= N; i++)
        if (!arr[i]) cout << i << '\n';

    return 0;
}
*/

// 3 - �Ҽ��� ������ ���� �̿�
int main()
{
    int M, N;
    cin >> M >> N;

    int max;
    for (int i = M; i <= N; i++)
    {
        bool flag = false;
        max = sqrt(i);   // ���������� ������ �����Ѵ�.
        if (max == 1 && i != 1)  // �������� 1�� ���� 2, 3
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