#include <iostream>
using namespace std;

// Ä·½¶È­°¡ ¹«³ÊÁø ´ëÇ¥ÀûÀÎ »ç·Ê

class SinivelCap
{
public:
    void Take() const
    {
        cout << "Äà¹° Ã³Ä¡¿ë Ä·½¶" << endl;
    }
};

class SneezeCap
{
public:
    void Take() const
    {
        cout << "ÀçÃ¤±â Ã³Ä¡¿ë Ä¸½¶" << endl;
    }
};

class SnuffleCap
{
public:
    void Take() const
    {
        cout << "ÄÚ¸·Èû Ã³Ä¡¿ë Ä¸½¶" << endl;
    }
};

class ColdPatient
{
public:
    void TakeSinivelCap(const SinivelCap& cap) const
    {
        cap.Take();
    }
    void TakeSneezeCap(const SneezeCap& cap) const
    {
        cap.Take();
    }
    void TakeSnuffleCap(const SnuffleCap& cap) const
    {
        cap.Take();
    }
};

int main()
{
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSnuffleCap(ncap);
    sufferer.TakeSneezeCap(zcap);

    return 0;
}