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
    SoSimple& AddNum(int n)  // �������� ��ȯ�ϴ� �Լ�
    {
        num += n;
        return *this;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)  // ob ��ü�� ���޵Ǹ� ob�� ��������� ȣ��
{
    cout << "return ����" << endl;
    return ob;   // ������ X -> ob ��ü�� ���纻�� ��ȯ��  (�ӽ� ��ü)
}

int main()
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowSimpleData();  // SimpleFuncObj�� ��ȯ�� ��ü�� ������� AddNum �Լ��� ȣ��ǰ�, �̾ AddNum �Լ��� ��ȯ�ϴ� �������� ������� ShowData �Լ��� ȣ��ȴ�.
    obj.ShowSimpleData();   // �������� �ӽð�ü�� �����, �� ����� �ٸ���.
    return 0;
}