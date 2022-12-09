#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Number {
    vector<int> array;
    vector<int> command;   // 문제에서는 2차원 배열로 주어짐
    vector<int> cutArr();
public:
    Number(vector<int> array, vector<int> command);
    int findNum();
};

Number::Number(vector<int> array, vector<int> command) {
    this-> array = array; this->command = command;
}
vector<int> Number::cutArr() {
    vector<int> result;
    for (int i=0; i<array.size(); i++) {
        if (i < command[0]-1 || i > command[1]-1) continue;
        result.push_back(array[i]);
    }
    return result;
}
int Number::findNum() {
    vector<int> re = cutArr();
    sort(re.begin(), re.end());
    for (int i=0; i<re.size(); i++)
        cout << re[i] << ' ';
    return re[command[2]-1];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i=0; i<commands.size(); i++) {
        Number mynum(array, commands[i]);
        answer.push_back(mynum.findNum());
    }
    return answer;
}

int main() {
    vector<int> arr = {1,5,2,6,3,7,4};
    vector<int> c = {2,5,3};
    Number mynum(arr, c);
    cout << mynum.findNum() << endl;
}
