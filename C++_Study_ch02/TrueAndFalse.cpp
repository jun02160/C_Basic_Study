#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int i = 0;

    cout << "true: " << true << endl;
    cout << "false: " << false << endl;

    while (true)
    {
        cout << i++ << ' ';
        if (i > num)
            break;
        cout << endl;
        
        // int���� 4byte, boolean���� 1byte�̴�.  => true�� false�� ���� 1�� 0�� �ǹ�������, �̵��� �������� ������ �ִٰ� �� ���� ����. 
        cout << "sizeof 1: " << sizeof(1) << endl;
        cout << "sizeof 0: " << sizeof(0) << endl;
        cout << "sizeof true: " << sizeof(true) << endl;

        return 0;
    }
}