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
            if (str[i + j] != find[j]) {   // ���ӵ� ���ڿ� ��
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            cnt++;
            i += find.length() - 1;   // ���� �ٱ� for���� ã�� ���ڿ��� ���̸�ŭ jump!
        }
    }
    cout << cnt << endl;
}