#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char* title;   // 책의 제목
    char* isbn;    // 국제표준도서번호
    int price;     // 책의 정가
public:
    Book(const char* mytitle, const char* myisbn, int myprice) :price(myprice)
    {
        title = new char[strlen(mytitle) + 1];   // this->title = new char[strlen(title)+1];  매개변수와 멤버의 이름을 같게 할 시 this 키워드로 구분!
        strcpy(title, mytitle);

        isbn = new char[strlen(myisbn) + 1];
        strcpy(isbn, myisbn);
    }
    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
    void ShowBookInfo()
    {
        cout << "제목: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "가격: " << price << endl;
    }
};

class EBook :public Book
{
private:
    char* DRMKey;
public:
    EBook(const char* title, const char* isbn, int price, const char* key) :Book(title, isbn, price)
    {
        DRMKey = new char[strlen(key) + 1];
        strcpy(DRMKey, key);
    }
    ~EBook()
    {
        delete[] DRMKey;
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "인증키: " << DRMKey << endl;
    }
};

int main()
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();

    cout << endl;

    EBook ebook("좋은 C++ ebook", "555-12333", 10000, "fdx-dsd");
    ebook.ShowEBookInfo();

    return 0;
}