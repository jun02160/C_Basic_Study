#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    vector<vector<int>> answer;

    //arr1�� ��(arr1[i].size()) = arr2�� ��(arr2.size())
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < arr2[0].size(); j++) {
            int sum = 0;
            int t = 0;
            for (int k = 0; k < arr1[0].size(); k++) {
                sum += arr1[i][k] * arr2[k][j];
                t++;
            }
            temp.push_back(sum);
        }
        answer.push_back(temp);
    }

    // 1 4  3 3
    // 3 2  3 3
    // 4 1    => 3X2 -- 1*3+4*3 1*3+4*3
                    //  3*3+2*3 2*3+3*3
                    //  4*3+1*3 + 

    // arr1�� ù ��° �迭[0][0], [0][1] - arr2�� ��� �迭�� ù ���� �ε��� 
    // arr1�� ù ��° �迭[0][0], [0][1] - arr2�� ��� �迭�� �� ���� �ε��� 
    return answer;
}

vector<vector<int>> solution2(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int Acol = arr1[0].size();
    int Arow = arr1.size();
    int Brow = arr2.size(); 
    int Bcol = arr2[0].size();

    // Acol == Brow  -> ������ ����� ��� ũ��  : Arow X Bcol

    vector<vector<int>> answer(Arow, vector<int>(Bcol));

    if (Acol == Brow) {
        for (int i = 0; i < Arow; i++) {
            for (int j = 0; j < Bcol; j++) {
                answer[i][j] = 0;   // 0���� �ʱ�ȭ
                for (int k = 0; k < Acol; k++) {
                    answer[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
    }
    return answer;

}