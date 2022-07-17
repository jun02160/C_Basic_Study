#include <iostream>

namespace Hybrid
{
    void HybFunc(void)
    {
        std::cout << "So simple function" << std::endl;
        std::cout << "In namespace Hybrid" << std::endl;
    }
}

int main()
{
    using Hybrid::HybFunc;  // using 선언 => 이후 이름공간 지정 없이 함수 호출 가능
    HybFunc();
    return 0;
}