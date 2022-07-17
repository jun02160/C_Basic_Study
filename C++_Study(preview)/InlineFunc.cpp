#include <iostream>

// C++ ����� �ζ��� �Լ� ���� "�Լ��� �ζ���ȭ �Ǿ���." 
// -> Ű���� inline�� ��ó���Ⱑ �ƴ�, �����Ϸ����� ó����
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