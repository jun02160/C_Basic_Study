// 처음 등장한 반복 문자의 최대 길이를 저장하는 멤버 필요
// 문자열을 저장하는 임시 변수 필요

#include <iostream>
#include <string>

using namespace std;

class MyExption {

};

class RCode {
    string str;   // 압축한 결과 문자열을 여기에 저장
    int maxlen;  // 최대 길이
    string temp;
public:
    RCode(string s);   // constructor
    int setResult();
};

RCode::RCode(string s) :str(s) {
    // 멤버의 초기값 설정
    temp = "";
    maxlen = 0;
}

// void RCode::setResult() {
//     char first = str[0];   // 반복 문자열의 첫번째 문자를 저장
//     temp += str[0];
//     for (int i=1; i<str.length(); i++) {
//         temp += str[i];
//         if (temp == str.substr(i+1, temp.length()-i) && temp.length()-i <str.length()) {
//             maxlen = temp.length();
//         }
//     }
//     cout << maxlen << endl;

//     if (maxlen == 1) {

//     } else if (maxlen >= 2) {

//     }
// }
int RCode::setResult() {
    int ans = str.length();
    for (int i=0; i<=str.length()/2; i++) {
        temp = "";
        for (int j=0; j<str.length(); j+=i) {
            // 현재 위치를 기준으로 substr과 다음 같은 길이의 substr가 같은지를 비교
            if (j+2*i <= str.length()) {   // index에 의한 오버플로우 방지
                if (str.substr(j, i) != str.substr(j+i, i)) {
                    temp += str.substr(j, i);
                    continue;
                }

                temp += str.substr(j, i);
                int cnt = 1;
                while (j+2*i <= ans && str.substr(j, i) == str.substr(j+i, i)) {
                    cnt ++;
                    j += i;
                }
                temp += to_string(cnt);
            } else {
                temp += str.substr(j);
                break;
            }
        }
        if (ans > temp.size()) ans = temp.size();
    }
    return ans;
}

// 최대 문자열의 길이가 >= 2인 경우, 앞쪽의 한 쌍 외에 그 뒤에 오는 쌍이 maxlen 보다 작거나 같은경우, 1인 경우, 큰 경우 세 가지 케이스로 분류하여 처리해야 한다. 
int solution(string str) {
    RCode mycode(str);
    return mycode.setResult();
}

