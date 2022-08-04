#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string find;

    getline(cin, str);
    getline(cin, find);

    int cnt = 0;

    for (int i = 0; i < str.length(); i++) {
        int flag = 0;    
        for (int j = 0; j < find.length(); j++) {
            if (str[i + j] != find[j]) {   // 연속된 문자열 비교
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            cnt++;
            i += find.length() - 1;   // 다음 바깥 for문은 찾는 문자열의 길이만큼 jump!
        }
    }
    cout << cnt << endl;
}