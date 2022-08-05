#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Girl;    // Girl이라는 이름이 클래스 이름임을 알림

class Boy
{
private:
    int height;
    friend class Girl;   // private 영역에도 friend 선언 가능 (선언 위치는 무관)
public:
    Boy(int len) :height(len)
    {}
    void ShowYourFriendInfo(Girl& frn);
};


class Girl
{
private:
    char phNum[20];
public:
    Girl(const char* num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy& frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
    cout << "Her phone number: " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
    cout << "His height: " << frn.height << endl;
}

int main()
{
    Boy boy(180);
    Girl girl("010-1234-5678");
    boy.ShowYourFriendInfo(girl);
    girl.ShowYourFriendInfo(boy);
}