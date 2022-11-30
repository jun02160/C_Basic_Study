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
    Person(const char* myname, int myage) {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    void ShowPersonInfo() const {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person() {
        delete[]name;
        cout << "called destructor!" << endl;
    }
};

int main()
{
    Person p1("Park Ye jun", 21);
    Person p2("Park Ye seo", 17);

    p2 = p1;
    p1.ShowPersonInfo();
    p2.ShowPersonInfo();
}