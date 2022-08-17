#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
    char* name;
    int age;
public:
    MyFriendInfo(char* myname)
    {
        name = new char[strlen(name) + 1];
        strcpy(name, myname);
    }
    ~MyFriendInfo()
    {
        delete[] name;
    }
    void ShowMyFriendInfo() const
    {
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
    }
};

class MyFriendDetailInfo :public MyFriendInfo
{
private:
    char* addr;
    char* phone;
public:
    MyFriendDetailInfo(char* myname, char* myaddr, char* myphone) :MyFriendInfo(myname)
    {
        addr = new char[strlen(myaddr) + 1];
        strcpy(addr, myaddr);

        phone = new char[strlen(myphone) + 1];
        strcpy(phone, myphone);
    }
    ~MyFriendDetailInfo()
    {
        delete[] addr;
        delete[] phone;
    }
    void ShowMyFriendDetailInfo() const
    {
        ShowMyFriendInfo();
        cout << "�ּ�: " << addr << endl;
        cout << "��ȭ: " << phone << endl << endl;
    }
};

int main()
{
    MyFriendDetailInfo d1("Jun", "Seoul", "010-0000-0000");
    d1.ShowMyFriendDetailInfo();
}