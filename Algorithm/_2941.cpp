#include <iostream>
#include <string>
using namespace std;

// ũ�ξ�Ƽ�� ���ĺ� �迭
string* croatia = new string[8]{
    "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
};

int main()
{
    string str;
    cin >> str;

    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        int index = -1;
        if (str.find(croatia[i]) != string::npos)
        {
            cnt++;
            index = str.find(croatia[i]);
        }

        if (str.find(croatia[i], index+1) != string::npos)
            cnt++;
    }

    cout << cnt << endl;
}