#include <iostream>
using namespace std;

// 기본 연료 자동차
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
        cout << "잔여 가솔린: " << gasolineGauge << endl;
    }
};

// 하이브리드 자동차
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
        cout << "잔여 전기량: " << electricGauge << endl;
    }
};


// 하이브리드 워터카
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
        cout << "잔여 워터량: " << waterGauge << endl;
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