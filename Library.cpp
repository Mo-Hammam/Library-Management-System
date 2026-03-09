#include <iostream>
#include <vector>

using namespace std;

class Book
{

protected:
    string name_book;
    string author_book;
    int id_book;

public:
    void info_book()
    {

        cout << "Enter ID: ";
        cin >> id_book;
        cout << endl;
        cout << "Enter Name: ";
        cin >> name_book;
        cout << endl;
        cout << "Enter Author: ";
        cin >> author_book;
        cout << endl;
    }
    void displayBook()
    {
        cout << "The Book of ID:" << id_book << endl;
        cout << "The Book of Name:" << name_book << endl;
        cout << "The Book of Author:" << author_book << endl;
    }
};

class User : Book
{
private:
    int id_user;
    string name_user;

public:
    void borrow_book(int id_book)
    {
    }
};

class Library
{

private:
    vector<Book> Books;

public:
    void addBook()
    {

        Book b1;
        b1.info_book();
        Books.push_back(b1);
    }

    void Display()
    {

        if (Books.empty())
        {
            cout << "No Books Founded\n";
            return;
        }
        else
        {

            for (int i = 0; i < Books.size(); i++)
            {
                Books[i].displayBook();
            }
        }
    }
};

int main()
{

    Library l1;
    l1.addBook();
    l1.Display();

    return 0;
}