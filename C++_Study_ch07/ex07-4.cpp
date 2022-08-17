#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char* title;   // å�� ����
    char* isbn;    // ����ǥ�ص�����ȣ
    int price;     // å�� ����
public:
    Book(const char* mytitle, const char* myisbn, int myprice) :price(myprice)
    {
        title = new char[strlen(mytitle) + 1];   // this->title = new char[strlen(title)+1];  �Ű������� ����� �̸��� ���� �� �� this Ű����� ����!
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
        cout << "����: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "����: " << price << endl;
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
        cout << "����Ű: " << DRMKey << endl;
    }
};

int main()
{
    Book book("���� C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();

    cout << endl;

    EBook ebook("���� C++ ebook", "555-12333", 10000, "fdx-dsd");
    ebook.ShowEBookInfo();

    return 0;
}