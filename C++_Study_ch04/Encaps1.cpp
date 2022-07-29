#include <iostream>
using namespace std;

// ķ��ȭ�� ������ ��ǥ���� ���

class SinivelCap
{
public:
    void Take() const
    {
        cout << "�๰ óġ�� ķ��" << endl;
    }
};

class SneezeCap
{
public:
    void Take() const
    {
        cout << "��ä�� óġ�� ĸ��" << endl;
    }
};

class SnuffleCap
{
public:
    void Take() const
    {
        cout << "�ڸ��� óġ�� ĸ��" << endl;
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