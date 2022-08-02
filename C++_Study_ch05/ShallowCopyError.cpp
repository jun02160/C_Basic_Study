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
    // 깊은 복사가 이뤄지기 위한 복사 생성자 정의 
    Person(const Person& copy) :age(copy.age)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
    }
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        delete[]name;
        cout << "called destructor!" << endl;   // 깊은 복사 시 -> 소멸자 객체 수만큼 호출 / 얕은 복사 시 -> 소멸자 한 번 호출(하나의 멤버를 포인터로 참조하는 형태이기 때문)
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