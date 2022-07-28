#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>    // 숫자를 문자열로 바꾸는 to_string() 함수를 사용하기 위함
using namespace std;

//////// 1 ////////
//int main()
//{
//    int N;
//    cin >> N;
//
//    int result = 0;
//    for (int i = 1; i <= N; i++) {
//        string str = to_string(i);
//        result += str.length();
//    }
//
//    cout << result;
//
//    return 0;
//}

//////// 2 //////////
//int main()
//{
//    int N;
//    cin >> N;
//
//    int result = 0;
//    for (int i = 1; i <= N; i++) {
//        int temp = i;
//        while (temp > 0) {
//            result++;
//            temp /= 10;
//        }
//    }
//    
//    cout << result;
//    return 0;
//}

//////// 3 //////////
int main()
{
    int N, result = 0;
    cin >> N;
    for (int i = 1; i <= N; i *= 10)
    {
        result += N-i+1;
    }

    cout << result;
    return 0;
}