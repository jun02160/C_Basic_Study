#include <iostream>

namespace mystd
{
    using namespace std;

    class ostream {
    public:
        ostream& operator<< (char* str);
        ostream& operator<< (char c);
        ostream& operator<< (int num);
        ostream& operator<< (double e);
        ostream& operator<< (ostream& (*fp)(ostream& ostm));
    };

    ostream& ostream::operator<<(char* str) {
        printf("%s", str);
        return *this;
    }
    ostream& ostream::operator<<(char c) {
        printf("%c", c);
        return *this;
    }
    ostream& ostream::operator<<(int num) {
        printf("%d", num);
        return *this;
    }
    ostream& ostream::operator<<(double e) {
        printf("%g", e);
        return *this;
    }
    ostream& ostream::operator<< (ostream& (*fp)(ostream& ostm)) {
        return fp(*this);
    }
    
    ostream& endl(ostream& ostm) {
        ostm << '\n';
        fflush(stdout);
        return ostm;
    }
    ostream cout;
}

int main() {
    using mystd::cout;
    using mystd::endl;

    cout << 3.14 << endl << 12 << endl;
    return 0;
}