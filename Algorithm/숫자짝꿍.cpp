#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Pair {
    vector<char> samelist;
    string x, y;
    void setList();  // cntlist와 samelist 처리
    bool isPossible();  // 같은 문자가 없으면 불가능 -> -1 반환
    int isRightPair(char c);   // x와 y에서 공통으로 가진 이 수가 짝의 조건에 해당하는지
    bool isIn(char c);
public:
    Pair(string x, string y);
    string getMax();
    
};

Pair::Pair(string x, string y) :x(x), y(y) { setList(); }
bool Pair::isIn(char c) {
    for (int i=0; i<samelist.size(); i++)
        if (samelist[i] == c) return true;
    return false;
}
void Pair::setList() {
    // 두 개의 수 중 하나에 대해서만 반복문을 돌면 짝으로 가능한 후보들을 찾을 수 있다
    for (int i=0; i<x.length(); i++) {
        if (isRightPair(x[i]) != -1 && !isIn(x[i])) {
            samelist.push_back(x[i]);
        }
    }
}
bool Pair::isPossible() {
    for (int i=0; i<x.length(); i++) {
        for (int j=0; j<y.length(); j++) {
            if (x[i] == y[j]) return true;  // 같은 게 하나라도 있으면 true (이게 홀수개인 경우는 나중에 고려)
        }
    }
    return false;
}

int Pair::isRightPair(char c) {
    // 해당 문자가 x와 y에 공통으로 들어있어야 함(없으면 -1 반환, 있으면 가능한 최대개수 반환)
    bool temp = false;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i=0; i<x.length(); i++) {
        if (x[i] == c) {
            temp = true;
            cnt1++;
        }
    }
    if (!temp) return -1;
    
    for (int i=0; i<y.length(); i++) {
        if (y[i] == c) {
            temp = true;
            cnt2++;
        } 
    }
    if (!temp) return -1;
    
     // samelist를 돌면서 셋팅
    int cnt;
    if (cnt1 > cnt2) cnt = cnt2;
    else cnt = cnt1;
    cout << "cnt: " << cnt << endl;
    return cnt;
}
string Pair::getMax() {
    if (!isPossible()) return "-1";
    sort(samelist.begin(), samelist.end());
    
    string result = "";
    for (int i=samelist.size()-1; i>=0; i--) {
        cout << "samelist[i]: " << samelist[i] << endl;
        int cnt = isRightPair(samelist[i]);
        for (int k=0; k<cnt; k++) result += samelist[i];
    }
    
    if (result[0] == '0') result = "0";
    return result;
}
string solution(string X, string Y) {
    string answer = "";
    Pair mypair(X, Y);
    answer = mypair.getMax();
    return answer;
}
