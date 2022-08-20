#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
    char name[100];
public:
    Employee(const char* name)
    {
        strcpy(this->name, name);
    }
    void ShowYourName() const
    {
        cout << "name: " << name << endl;
    }
    virtual int GetPay() const = 0;
    virtual void ShowSalaryInfo() const = 0;
};

// 정규직 직원에 관한 클래스
class PermanentWorker :public Employee
{
private:
    int salary;   // 월 급여
public:
    PermanentWorker(const char* name, int money)
        :Employee(name), salary(money)
    { }
    int GetPay() const
    {
        return salary;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;
    }
};

// 임시직 직원에 관한 클래스
class TemporaryWorker :public Employee
{
private:
    int workTime;     // 이 달에 일한 시간의 형태
    int payPerHour;   // 시간당 급여
public:
    TemporaryWorker(const char* name, int pay) :Employee(name), workTime(0), payPerHour(pay)
    { }
    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
};

// 영업직 직원에 관한 클래스
class SalesWorker :public PermanentWorker
{
private:
    int salesResult;    // 월 판매실적
    double bonusRatio;   // 상여금 비율
public:
    SalesWorker(const char* name, int money, double ratio) :PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
    { }
    void AddSalesResult(int value)
    {
        salesResult += value;
    }
    int GetPay() const
    {
        return PermanentWorker::GetPay()    // PermanentWorker의 GetPay 함수 호출
            + (int)(salesResult * bonusRatio);
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "salary: " << GetPay() << endl << endl;   // SalesWorker의 GetPay 함수 호출 (by 함수 오버라이딩)
    }
};

namespace RISK_LEVEL
{
    enum {
        RISK_A = 30,
        RISK_B = 20,
        RISK_C = 10
    };
}

// 해외 영업직 직원에 관한 클래스
class ForeignSalesWorker :public SalesWorker
{
private:
    int riskLevel;
public:
    ForeignSalesWorker(const char* name, int money, double ratio, int level) :SalesWorker(name, money, ratio), riskLevel(level)
    { }
    int GetRiskPay() const
    {
        return (int) (SalesWorker::GetPay() * (riskLevel / 100.0));
    }
    int GetPay() const
    {
        return SalesWorker::GetPay() + GetRiskPay();
    }
    void ShowSalaryInfo() const
    {
        ShowSalaryInfo();
        cout << "risk pay: " << GetRiskPay() << endl;
        cout << "sum: " << GetPay() << endl;
    }
};

// 컨트롤 클래스
class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;
public:
    EmployeeHandler() :empNum(0)
    { }
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    void ShowTotalSalart() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
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
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 해외 영업직 등록
    ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Park", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Kim", 1000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(7000);
    handler.AddEmployee(fseller3);
        

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalart();
    return 0;
}