#include <iostream>


// �Լ��� �����
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
    std::cout << "BestCom�� ������ �Լ�" << std::endl;
    PretFunc();
    ProgComImpl::SimpleFunc();
}


void ProgComImpl::SimpleFunc()
{
    std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}

void BestCompImpl::PretFunc()
{
    std::cout << "BestCom�� ������ �Լ�2" << std::endl;
}