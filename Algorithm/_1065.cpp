#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N; 
    cin >> N;

    int num = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i < 100)
            num++;
        else
        {
            string strN = to_string(i);
            if (strN[0] - strN[1] == strN[1] - strN[2])   // 등차수열의 정의 이용
                num++;
        }
    }

    cout << num << endl;
    return 0;
}