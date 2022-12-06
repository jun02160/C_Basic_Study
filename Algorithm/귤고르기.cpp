// 여러 개의 귤들을 크기별로 분류하고 각 크기마다 몇 개씩 존재하는지 저장 
// -> 판매하고 싶은 개수에서 최소 개의 종류로 구성할 수 있는 경우의 수를 찾는 문제
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tangerine {
    int pick;
    vector<int> tangerines;
    vector<int> sizes;   // index+1 = size 로, 크기를 기준으로 분류(해당 인덱스에서 카운팅 +1)
    int getMaxSize(const vector<int>& arr);   // 최대 크기 구하는 함수
    void setSizes();
public:
    Tangerine(int k, vector<int> tangerine);   // constructor
    int getMinCnt();   // 가능한 서로 다른 종류의 최솟값을 구하는 함수
    friend ostream& operator<<(ostream& os, const Tangerine& t);
};

Tangerine::Tangerine(int k, vector<int> tangerine) :pick(k), tangerines(tangerine) {}
void Tangerine::setSizes() {
    // size 배열 모두 0으로 초기화(벡터의 크기와 초기값 모두 할당) -> 존재하지 않더라도 0으로 설정
    for (int i=0; i<getMaxSize(tangerines); i++) {
        sizes.push_back(0);
    }
    for (int i=0; i<tangerines.size(); i++) {
        sizes[tangerines[i]-1]++;   // 해당 사이즈의 개수를 하나씩 카운팅
    }
}
int Tangerine::getMaxSize(const vector<int>& arr) {
    int max = arr[0];
    for (int i=1; i<arr.size(); i++) 
        if (arr[i] > max) max = arr[i];
    return max;   // 최대 크기 값이 저장
}
int Tangerine::getMinCnt() {
    this->setSizes();   // sizes 배열 구성
    sort(sizes.begin(), sizes.end());   // sizes 배열 정렬 (오름차순)

    int sum = 0;
    int cnt = 0;
    for (int i=sizes.size()-1; i>=0; i--) {
        sum += sizes[i];
        cnt++;
        if (sum >= pick) return cnt;
    }
}
ostream& operator<<(ostream& os, const Tangerine& t) {
    os << "size 배열의 값: ";
    for (int i=0; i<t.sizes.size(); i++) {
        os << t.sizes[i] << ' ';
    }
    os << endl;
    return os;
}


// 서로 다른 종류의 최솟값을 리턴
int solution(int k, vector<int> tangerine) {
    Tangerine t(k, tangerine);
    return t.getMinCnt();
}

int main() {
    int k = 6;
    vector<int> tangerine = {1,3,2,5,4,5,2,3};
    Tangerine t(k, tangerine);
    cout << t.getMinCnt() << endl;
    cout << t << endl;

}
