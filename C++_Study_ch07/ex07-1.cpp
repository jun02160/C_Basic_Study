#include <iostream>
using namespace std;

// �⺻ ���� �ڵ���
class Car
{
private:
    int gasolineGauge;
public:
    Car(int n) :gasolineGauge(n)
    {

    }
    void GetGasGauge()
    {
        cout << "�ܿ� ���ָ�: " << gasolineGauge << endl;
    }
};

// ���̺긮�� �ڵ���
class HybridCar :public Car
{
private:
    int electricGauge;
public:
    HybridCar(int cn, int hn) : Car(cn), electricGauge(hn)
    {

    }
    void GetElecGauge()
    {
        GetGasGauge();
        cout << "�ܿ� ���ⷮ: " << electricGauge << endl;
    }
};


// ���̺긮�� ����ī
class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int cn, int hn, int hw) : HybridCar(cn, hn), waterGauge(hw)
    {

    }
    void ShowCurrentGauge()
    {
        GetElecGauge();
        cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
    }
};

int main()
{
    Car c1(4);
    HybridCar c2(10, 4);
    HybridWaterCar c3(100, 3, 20);

    c1.GetGasGauge();
    c2.GetElecGauge();
    c3.ShowCurrentGauge();
}