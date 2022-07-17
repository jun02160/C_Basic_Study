#include <iostream>


// 함수의 선언부
namespace BestCompImpl
{
    void SimpleFunc();
}

namespace ProgComImpl
{
    void SimpleFunc();
}

namespace BestCompImpl
{
    void PretFunc();
}

int main()
{
    BestCompImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();

    return 0;
}

void BestCompImpl::SimpleFunc()
{
    std::cout << "BestCom이 정의한 함수" << std::endl;
    PretFunc();
    ProgComImpl::SimpleFunc();
}


void ProgComImpl::SimpleFunc()
{
    std::cout << "ProgCom이 정의한 함수" << std::endl;
}

void BestCompImpl::PretFunc()
{
    std::cout << "BestCom이 정의한 함수2" << std::endl;
}