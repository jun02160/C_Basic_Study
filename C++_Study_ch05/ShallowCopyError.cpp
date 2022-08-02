#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char* name;
    int age;
public:
    Person(const char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    // ���� ���簡 �̷����� ���� ���� ������ ���� 
    Person(const Person& copy) :age(copy.age)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }
    void ShowPersonInfo() const
    {
        cout << "�̸�: " << name << endl;
        cout << "����: " << age << endl;
    }
    ~Person()
    {
        delete[]name;
        cout << "called destructor!" << endl;   // ���� ���� �� -> �Ҹ��� ��ü ����ŭ ȣ�� / ���� ���� �� -> �Ҹ��� �� �� ȣ��(�ϳ��� ����� �����ͷ� �����ϴ� �����̱� ����)
    }
};

int main()
{
    Person man1("Park Ye Jun", 21);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}