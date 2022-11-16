#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

// 소수를 판별하는 함수
bool isPrime(long long n) {
    if (n == 2) return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 숫자 n을 k진법으로 변환하는 함수
string changeNum(int n, int k) {
    string result = "";
    while (n > 0) {
        result = (char)('0' + (n % k)) + result;
        n /= k;
    }

    return result;
}

int countPrime(string str) {
    int cnt = 0;
    string temp = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '0') {
            temp += str[i];
        }
        else {
            if (temp != "1" && temp != "") {
                cout << "temp: " << temp << endl;
                cout << "str: " << stoll(temp) << endl;
                if (isPrime(stoll(temp)))
                    cnt++;
            }
            temp = "";
        }

    }
    if (temp != "1" && temp != "" && temp != "0") {
        if (isPrime(stoll(temp))) cnt++;
    }

    return cnt;
}

int solution(int n, int k) {
    int answer = -1;
    string num = changeNum(n, k);
    cout << num << endl;
    answer = countPrime(num);
    return answer;
}

int main() {
    cout << solution(3,3) << endl;
}