#include <iostream>

namespace JunImpl {
    void SimpleFunc(void) {
        std::cout << "JunComp�� ������ �Լ�" << std::endl;

    }
}

namespace SeoImpl {
    void SimpleFunc(void) {
        std::cout << "SeoComp�� ������ �Լ�" << std::endl;
    }
}

int main(void) {
    JunImpl::SimpleFunc();   // �������� �����ڷ� �ش� �̸������� ����
    SeoImpl::SimpleFunc();
}