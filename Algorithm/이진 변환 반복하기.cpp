
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int deleteZero(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0') result += s[i];
    }
    cout << "deleteZero: " << result << endl;
    return result.length();  // 0 제거 후의 길이
}

string toBinary(int dec) {
    string result = "";
    while (dec > 0) {
        result = (char)((dec % 2) + '0') + result;
        dec /= 2;
    }
    cout << "toBinary result: " << result << endl;
    return result;
}

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0;
    int zero = 0;
    int bin = 0;   // 이진 변환할 결과값 저장 (-> 최종 목표 : 1 만들기)

    while (true) {
        int len = deleteZero(s);  // len: 0 제거 후의 길이가 저장 / zero: 0의 개수만큼 추가
        zero += s.length() - len;
        cout << "len: " << len << endl;
        count++;   // 이진 변환할 때마다 카운트 1씩 증가
        if (len == 1) break;
        s = toBinary(len);
        cout << "s: " << s << endl;
        cout << count << " " << zero << endl;
    }

    answer.push_back(count);
    answer.push_back(zero);


    return answer;
}
