#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// ������ ���� ������ ���� Ŭ���� -> ���Ͽ� ������ ������ �����
class PermanentWorker 
{
private:
    char name[100];
    int salary;    // �Ŵ� �����ؾ� �ϴ� �޿���
public:
    PermanentWorker(const char* name, int money)
        :salary(money)
    {
        strcpy(this->name, name);
    }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        cout << "name: " << name << endl;
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// ������ �̸��� �޿������� ���� �� �����ϱ� ���� Ŭ���� -> ���α׷��� ��ɺ� ������ ����
class EmployeeHandler
{
private:
    PermanentWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() :empNum(0)
    {

    }
    // ���ο� ���� ������ ���
    void AddEmployee(PermanentWorker* emp)
    {
        empList[empNum++] = emp;
    }
    // ��� ������ �̹� �� �޿����� ���
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    // �̹� �� �޿��� �Ѿ� ���
    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
        cout << "salary sum: " << sum << endl;
    }
    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; i++)
            delete empList[i];
    }
};

int main()
{
    // ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü ����
    EmployeeHandler handler;

    // ���� ���
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("PARK", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // �̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowAllSalaryInfo();

    // �̹� �޿� �����ؾ� �� �޿��� ����
    handler.ShowTotalSalary();
    return 0;
}