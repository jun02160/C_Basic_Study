#include <iostream>
#include <string>
using namespace std;

int main()
{

    while (true) 
    {
        int num;
        cin >> num;
        if (num == 0) break;

        string str = to_string(num);

        bool flag = true;    // 펠린드롬인지 판별하는 상태값

        for (int i = 0, j = str.length()-1; i < str.length(); i++, j--)
        {
            if (str[i] != str[j]) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
           
    }
}