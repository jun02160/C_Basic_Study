#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;   // 장전된 총알의 수
public:
    Gun(int bnum) :bullet(bnum)
    { }
    void shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
};

class Police 
{
private:
    int handcuffs;   // 소유한 수갑의 수
    Gun* pistol;     // 소유하고 있는 권총
public:
    Police(int bnum, int bcuff) :handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    void PutHandcuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void shot()
    {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->shot();
    }
    ~Police()
    {
        if (pistol == NULL)
            delete pistol;
    }
};


int main()
{
    Police pman(5, 3);
    pman.shot();
    pman.PutHandcuff();

    Police npman(0, 3);   //권총을 소유하지 않은 경찰
    npman.shot();
    npman.PutHandcuff();
    return 0;
}