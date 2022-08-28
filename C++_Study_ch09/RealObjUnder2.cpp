#include <iostream>
using namespace std;

// 클래스 Data를 흉내 낸 영역
typedef struct Data
{
    int data;
    void (*ShowData)(Data*);
    void (*Add)(Data*, int);
} Data;

void ShowData(Data* THIS)
{
    cout << "Data: " << THIS->data << endl;
}

void Add(Data* THIS, int num)
{
    THIS->data += num;
}

int main()
{
    // 두 객체는 ShowData, Add 함수를 공유한다. 
    Data obj1 = { 15, ShowData, Add };
    Data obj2 = { 7, ShowData, Add };

    obj1.Add(&obj1, 17);
    obj2.Add(&obj2, 9);
    obj1.ShowData(&obj1);
    obj2.ShowData(&obj2);

    return 0;
}