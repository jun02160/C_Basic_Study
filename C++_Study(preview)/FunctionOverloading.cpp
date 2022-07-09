#include <iostream>

// �Լ� �����ε��� �Ű������� �ڷ��� �Ǵ� ������ ���̰� ���� ���� ���� (��ȯ���� ����)
void MyFunc(void)
{
    std::cout << "MyFunc(void) called" << std::endl;
}

void MyFunc(char c)
{
    std::cout << "MyFunc(char c) called" << std::endl;
}

void MyFunc(int a, int b)
{
    std::cout << "MyFunc(int a, int b) called" << std::endl;
}

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void swap(char* n1, char* n2)
{
    char temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main()
{
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);

    int num1 = 20, num2 = 30;
    swap(&num1, &num2);
    std::cout << num1 << ' ' << num2 << std::endl;

    char ch1 = 'A', ch2 = 'Z';
    swap(&ch1, &ch2);
    std::cout << ch1 << ' ' << ch2 << std::endl;

    
    return 0;
}