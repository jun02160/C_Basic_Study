#include <iostream>

namespace JunImpl {
    void SimpleFunc(void) {
        std::cout << "JunComp이 정의한 함수" << std::endl;

    }
}

namespace SeoImpl {
    void SimpleFunc(void) {
        std::cout << "SeoComp이 정의한 함수" << std::endl;
    }
}

int main(void) {
    JunImpl::SimpleFunc();   // 범위지정 연산자로 해당 이름공간을 지정
    SeoImpl::SimpleFunc();
}