#include <iostream>
using namespace std;

class First
{
private:
    char* strOne;
public:
    First(const char* str)
    {
        strOne = new char[strlen(str) + 1];
    }
    ~First()
    {
        cout << "~First()" << endl;
        delete[]strOne;
    }
};

class Second :public First
{
private:
    char* strTwo;
public:
    Second(const char* str1, const char* str2) :First(str1)
    {
        strTwo = new char[strlen(str2) + 1];
    }
    ~Second()
    {
        cout << "~Second()" << endl;
        delete[]strTwo;
    }
};

int main()
{
    First* ptr = new Second("simple", "complex");   // First 클래스의 소멸자만 호출 -> 메모리 누수
    delete ptr;
    return 0;
}