#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) :num(n)
    {

    }
    SoSimple(SoSimple& copy) :num(copy.num)
    {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    void ShowSimpleData()
    {
        cout << "num: " << num << endl;
    }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowSimpleData();
}

int main()
{
    SoSimple obj(7);
    cout << "�Լ�ȣ�� ��" << endl;
    SimpleFuncObj(obj);   // �ʱ�ȭ�� ����� �Լ��� �Ű������� ob��ü -> ob ��ü�� ���� �����ڰ� ȣ��Ǹ鼭, obj ��ü�� ���ڷ� ���޵Ǿ�� �Ѵ�.
    cout << "�Լ�ȣ�� ��" << endl;
    return 0;
}