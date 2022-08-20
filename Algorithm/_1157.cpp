#include <iostream>
#include <string>
using namespace std;

#define ALPHABET 26

// 'A'(65) ~ 'Z'(90)
// 'a'(97) ~ 'z'(122)

int* alphabet = new int[ALPHABET]{ 0, };

int getMax(int* arr)
{
    int maxIndex = 0;
    for (int i = 0; i < ALPHABET; i++)
    {
        if (arr[maxIndex] < arr[i]) 
            maxIndex = i;
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        // 최다 빈도의 알파벳이 두 개 이상인 경우 ? 출력
        if (arr[maxIndex] == arr[i] && maxIndex != i)
            return -1;
    }

    return maxIndex;
}

int main()
{
    string word;
    getline(cin, word);

    for (int i = 0; i < word.size(); i++)
    {
        // 대문자의 경우, 소문자로 변환
        if (word[i] >= 'A' && word[i] <= 'Z') 
            word[i] += 32;
        
        
        alphabet[word[i]-'a']++;
    }

    if (getMax(alphabet) != -1)
        cout << (char)(getMax(alphabet)+65) << endl;  // 대문자로 출력
    else
        cout << '?' << endl;
}