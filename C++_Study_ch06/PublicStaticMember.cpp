#include <iostream>
using namespace std;

class SoSimple
{
public:
    // static ����� private ���� ���� ��, �ش� Ŭ���������� ������ ���������� public ���� ���� �� ��𼭵� ������ ����������. 
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt = 0;

int main()
{
    cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;   // ��ü ���� ���� �̹� �޸� ������ �Ҵ�Ǿ� �����Ƿ� ���� ����� �����ϴ�. 
    SoSimple sim1;
    SoSimple sim2;

    // public static ����� ������ ���� Ŭ������ �̸��� �̿��ؼ� �����ϴ� ���� ����.  for Ŭ���� ��� �������� ����
    cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << endl;

    cout << sim1.simObjCnt << "��° SoSimple ��ü" << endl;
    cout << sim2.simObjCnt << "��° SoSimple ��ü" << endl;

    return 0;
}