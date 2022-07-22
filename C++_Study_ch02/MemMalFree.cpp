#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

char* MakeStrAdr(int len)
{
    char* str = (char*)malloc(sizeof(char) * len);   // malloc의 형 변환 절차와 바이트 크기 지정을 간략화할 수 있는 키워드: new
    return str;
}

int main()
{
    char* str = MakeStrAdr(20);
    strcpy(str, "I am so happy~");
    cout << str << endl;
    free(str);
    return 0;
}