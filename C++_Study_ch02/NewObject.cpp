#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class Simple
{
public:
    Simple()
    {
        cout << "i'm simple constructor" << endl;
    }
};

int main()
{
    cout << "case 1: ";
    Simple* sp1 = new Simple;  // ��ü�� �����ϱ� ���ؼ��� �ݵ�� new Ű���带 ����ؾ� ��

    cout << "case 2: ";
    Simple* sp2 = (Simple*)malloc(sizeof(Simple) * 1);

    cout << endl << "end of main" << endl;
    delete sp1;
    free(sp2);
    return 0;
}
