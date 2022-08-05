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
    void SimpleFunc()
    {
        cout << "SimpleFunc : " << num << endl;
    }
    void SimpleFunc() const
    {
        cout << "SimpleFunc const : " << num << endl;
    }
};

// 전달되는 인자를 참조자로 받으며, const 멤버함수를 호출하는 함수
void YourFunc(const SoSimple& obj)
{
    obj.SimpleFunc();
}

int main()
{
    SoSimple obj(2);
    const SoSimple obj2(20);

    obj.SimpleFunc();
    obj2.SimpleFunc();

    YourFunc(obj);
    YourFunc(obj2);
    return 0;
}