#include <iostream>

// C++ 기반의 인라인 함수 정의 "함수가 인라인화 되었다." 
// -> 키워드 inline은 전처리기가 아닌, 컴파일러에서 처리함
inline int SQUARE(int x)
{
    return x * x;
}

template <typename T>
inline T SQUARE2(T x)
{
    return x * x;
}

int main()
{
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(12) << std::endl;
    std::cout << SQUARE2(5.5) << std::endl;
    return 0;
}