#include <iostream>
using namespace std;

class CountryArea
{
public:
    const static int RUSSIA = 1707540;
    const static int CANADA = 998467;
    const static int CHINA = 957290;
    const static int SOUTH_KOREA = 9922;
};

int main()
{
    // 상수에 접근하기 위해 굳이 객체를 생성할 필요는 없다.
    cout << "러시아 면적: " << CountryArea::RUSSIA << "km^2" << endl;
    cout << "캐나다 면적: " << CountryArea::CANADA << "km^2" << endl;
    cout << "중국 면적: " << CountryArea::CHINA << "km^2" << endl;
    cout << "대한민국 면적: " << CountryArea::SOUTH_KOREA << "km^2" << endl;

    return 0;
}