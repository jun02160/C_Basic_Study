#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    // �ٱ� - ���� > ���� - ����
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= j)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }*/

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cout << '*';
        }
        cout << endl;
    }
}