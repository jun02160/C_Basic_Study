#include <iostream>
#include <string>
using namespace std;

// 크로아티아 알파벳 배열
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
        for (int j = 0; j < str.length(); j++)
        {
            // cout << croatia[i] << endl;
            if (str.find(croatia[i]) == string::npos)
                break;
            else if (str.find(croatia[i], j) <= j) {
                cout << j << endl;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}