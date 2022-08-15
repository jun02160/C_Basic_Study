#include <iostream>
using namespace std;

class SoBase
{
private:
    int baseNum;
public:
    SoBase() :baseNum(20)
    {
        cout << "SoBase()" << endl;
    }
    SoBase(int n) :baseNum(n)
    {
        cout << "SoBase(int n)" << endl;
    }
    void ShowBaseData()
    {
        cout << baseNum << endl;
    }
};