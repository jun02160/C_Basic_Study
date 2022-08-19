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
    virtual int GetPay() const
    {
        return 0;
    }
    virtual void ShowSalaryInfo() const
    { }
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

    // 직원 등록 
    // - 정규직
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("PARK", 5000));
    handler.AddEmployee(new PermanentWorker("LEE", 500));

    // - 임시직
    TemporaryWorker* alba = new TemporaryWorker("JUN", 700);
    alba->AddWorkTime(5);    // 5시간 일한 결과 등록
    handler.AddEmployee(alba);

    // - 영업직
    SalesWorker* seller = new SalesWorker("HONG", 1000, 0.1);
    seller->AddSalesResult(7000);   // 영업실적 7000
    handler.AddEmployee(seller);

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalart();
    return 0;
}