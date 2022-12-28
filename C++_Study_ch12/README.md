## C++의 표준과 표준 String 클래스

> String 클래스에서 구현된 연산자 오버로딩을 살펴보며 이해해보자!
> 

C++ 표준 라이브러리에는 string 이라는 이름의 클래스가 정의되어 있다. 즉, 원시타입으로 존재하지 않지만 그만큼 비중 있게 쓰이는 문자열을 다른 타입과 동일하게 처리하고자 하는 목적으로 <string> 헤더 파일에 연산자 오버로딩한 여러 형태를 구현하여 클래스로 제공하는 것이다. 

### 표준 string 클래스의 분석

1. 문자열을 인자로 전달받는 생성자의 정의
    
    ```cpp
    string str = "I like";
    string str1("string class");
    ```
    
2. 생성자, 소멸자, 복사 생성자, 대입 연산자의 정의
    
    다루고자 하는 문자열은 길이가 일정하지 않다. 따라서 문자열의 저장을 위한 메모리 공간을 생성자 내에서 동적 할당 해야 하고, 소멸자에서는 이를 명시적으로 소멸시켜야 한다. 또한, 깊은 복사를 하는 복사 생성자와 대입 연산자를 정의해야 한다. 
    
3. 결합된 문자열로 초기화된 객체를 반환하는 + 연산자의 오버로딩
    
    가능한 + 연산자의 반환값
    
    - 문자열의 주소 값
    - string 객체가 가진 문자열을 이어붙이기 한 문자열  ✅무문자열으
4. 문자열을 덧붙이는 += 연산자의 오버로딩
5. 내용 비교를 하는 == 연산자의 오버로딩
6. 콘솔 입출력이 가능하게 하는 <<, >> 연산자의 오버로딩

### 직접 구현

```cpp
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
```
