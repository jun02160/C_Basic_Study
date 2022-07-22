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
        
        // int형은 4byte, boolean형은 1byte이다.  => true와 false는 각각 1과 0을 의미하지만, 이들이 정수값을 가지고 있다고 할 수는 없다. 
        cout << "sizeof 1: " << sizeof(1) << endl;
        cout << "sizeof 0: " << sizeof(0) << endl;
        cout << "sizeof true: " << sizeof(true) << endl;

        return 0;
    }
}