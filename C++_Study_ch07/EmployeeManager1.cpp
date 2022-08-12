#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 정규직 직원 관리를 위한 클래스 -> 파일에 저장할 데이터 저장용
class PermanentWorker 
{
private:
    char name[100];
    int salary;    // 매달 지불해야 하는 급여액
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

// 정규직 이름과 급여정보를 저장 및 관리하기 위한 클래스 -> 프로그램의 기능별 단위로 구성
class EmployeeHandler
{
private:
    PermanentWorker* empList[50];
    int empNum;
public:
    EmployeeHandler() :empNum(0)
    {

    }
    // 새로운 직원 정보의 등록
    void AddEmployee(PermanentWorker* emp)
    {
        empList[empNum++] = emp;
    }
    // 모든 직원의 이번 달 급여정보 출력
    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < empNum; i++)
            empList[i]->ShowSalaryInfo();
    }
    // 이번 달 급여의 총액 출력
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
    // 직원관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
    EmployeeHandler handler;

    // 직원 등록
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("PARK", 1500));
    handler.AddEmployee(new PermanentWorker("JUN", 2000));

    // 이번 달에 지불해야 할 급여의 정보
    handler.ShowAllSalaryInfo();

    // 이번 달에 지불해야 할 급여의 총합
    handler.ShowTotalSalary();
    return 0;
}