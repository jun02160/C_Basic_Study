#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) :num(n)
    {

    }
    SoSimple(SoSimple& copy) :num(copy.num)
    {
        cout << "Called SoSimple(SoSimple &copy)" << endl;
    }
    void ShowSimpleData()
    {
        cout << "num: " << num << endl;
    }
    SoSimple& AddNum(int n)  // 참조값을 반환하는 함수
    {
        num += n;
        return *this;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)  // ob 객체가 전달되며 ob의 복사생성자 호출
{
    cout << "return 이전" << endl;
    return ob;   // 참조형 X -> ob 객체의 복사본이 반환됨  (임시 객체)
}

int main()
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowSimpleData();  // SimpleFuncObj가 반환한 객체를 대상으로 AddNum 함수가 호출되고, 이어서 AddNum 함수가 반환하는 참조값을 대상으로 ShowData 함수가 호출된다.
    obj.ShowSimpleData();   // 위에서는 임시객체의 존재로, 두 결과는 다르다.
    return 0;
}