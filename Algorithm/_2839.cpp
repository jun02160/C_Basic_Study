#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int cnt = 0;
    while (N >= 0)
    {
        if (N % 5 == 0)
        {
            cnt += N / 5;
            cout << cnt << endl;
            break;
        }
        N -= 3;
        cnt++;
    }
    
    if (N < 0)
    {
        cout << "-1" << endl;
    }
}