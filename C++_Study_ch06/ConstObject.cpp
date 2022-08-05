#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) :num(n)
    {}
    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }
    void ShowData() const
    {
        cout << "num: " << num << endl;
    }
};

int main()
{
    const SoSimple obj(7);
    // obj.AddNum(20);  // const 함수가 아니므로 호출 불가능
    obj.ShowData();
    return 0;
}