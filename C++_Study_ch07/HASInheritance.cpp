#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;   // ������ �Ѿ��� ��
public:
    Gun(int bnum) :bullet(bnum)  
    { }
    void shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police :public Gun
{
private:
    int handcuffs;   // ������ ������ ��
public:
    Police(int bnum, int bcuff) :Gun(bnum), handcuffs(bcuff)
    { }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
};


int main()
{
    Police pman(5, 3);
    pman.shot();
    pman.PutHandcuff();
    return 0;
}