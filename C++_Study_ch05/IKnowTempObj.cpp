#include <iostream>
using namespace std;

class Temporary
{
private:
    int num;
public:
    Temporary(int n) :num(n)
    {
        cout << "create obj: " << num << endl;
    }
    ~Temporary()
    {
        cout << "destroy obj: " << num << endl;
    }
    void ShowTempInfo()
    {
        cout << "My num is " << num << endl;
    }
};

int main()
{
    Temporary(100);
    cout << "********** after make!" << endl << endl;

    Temporary(200).ShowTempInfo();  // 임시객체의 참조값.ShowTempInfo();
    cout << "********** after make!" << endl << endl;

    const Temporary& ref = Temporary(300);
    cout << "********** end of main!" << endl << endl;
    return 0;
}