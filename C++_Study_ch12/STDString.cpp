#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    int len;
    char* str;
public:
    String();
    String(const char* s);
    String(const String& s);
    ~String();
    String& operator= (const String& s);   // 대입 연산자
    String& operator+= (const String& s);  // 문자열 이어붙이기 연산자
    bool operator==(const String& s);   // 비교 연산자
    String operator+(const String& s);   // 문자열 더하기 연산자

    // 입출력 연산자 오버로딩
    friend ostream& operator<< (ostream& os, const String& s);
    friend istream& operator>> (istream& is, String& s);
};

String::String() { len = 0; str = NULL; }
String::String(const char* s) {
    len = strlen(s);
    str = new char[len];
    strcpy(str, s);
}
String::String(const String& s) {
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
}
String::~String() {
    if (str != NULL) delete[]str;
}
String& String::operator=(const String& s) {
    if (str != NULL) delete[] str;
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
    return *this;
}
String& String::operator+=(const String& s) {
    len += (s.len - 1);
    char* tempstr = new char[len];
    strcpy(tempstr, str);
    strcat(tempstr, s.str);

    if (str != NULL) delete[] str;
    str = tempstr;
    return *this;
}
bool String::operator==(const String& s) {
    return strcmp(str, s.str) ? false : true;
}
String String::operator+ (const String& s) {
    char* tempstr = new char[len + s.len - 1];
    strcpy(tempstr, str);
    strcat(tempstr, s.str);

    String temp(tempstr);   // temp = tempstr
    delete[]tempstr;
    return temp;
}
ostream& operator<<(ostream& os, const String& s) {
    os << s.str;
    return os;
}
istream& operator>>(istream& is, String& s) {
    is >> s.str;
    return is;
}