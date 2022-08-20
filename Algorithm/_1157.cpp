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
        // �ִ� ���� ���ĺ��� �� �� �̻��� ��� ? ���
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
        // �빮���� ���, �ҹ��ڷ� ��ȯ
        if (word[i] >= 'A' && word[i] <= 'Z') 
            word[i] += 32;
        
        
        alphabet[word[i]-'a']++;
    }

    if (getMax(alphabet) != -1)
        cout << (char)(getMax(alphabet)+65) << endl;  // �빮�ڷ� ���
    else
        cout << '?' << endl;
}