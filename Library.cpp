#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Book
{

protected:
    string name_book;
    string author_book;

public:
    int id_book;
    bool availbale = true;
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
        cout << "-----------------------------------------------\n";
        cout << setw(10) << "The Book of ID:" << setw(10) << id_book << endl;
        cout << "-----------------------------------------------\n";
        cout << setw(10) << "The Book of Name:" << setw(10) << name_book << endl;
        cout << "-----------------------------------------------\n";
        cout << setw(10) << "The Book of Author:" << setw(10) << author_book << endl;
        cout << "-----------------------------------------------\n";
    }
};

class User : Book
{
private:
    int id_user;
    string name_user;

public:
    void setNameUser(string s)
    {
        name_user = s;
    }
    string getNameUser()
    {
        return name_user;
    }

    void info_user()
    {
        cout << "Enter ID User: ";
        cin >> id_user;
        cout << "Enter Name User: ";
        cin >> name_user;
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
            cout << "No Books Founded❗❗❗❗\n";
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
    void SearchBook(int bookSearch)
    {

        // cout<<"Enter the ID of Book to Search it:";             // this lines write in  switch of Search Book
        // cin>>bookSearch;                                     // this lines write in  switch of Search Book
        if (Books.empty())
        {

            cout << "No Books Founded❗❗❗❗\n";
            return;
        }
        else
        {
            for (int i = 0; i < Books.size(); i++)
            {
                if (Books[i].id_book == bookSearch)
                {
                    cout << "The Book is Found✅✅✅\n";
                    Book bb;
                    bb.info_book();
                    bb.displayBook();
                }
                else
                {
                    cout << "This Book isn't Found❗❗❗❗\n";
                }
            }
        }
    }

    void borrow_book(Book borrow_book, User user)

    {

        // user.info_user();                        //Calling it in switch case;
        // user.setNameUser();

        if (borrow_book.availbale)
        {
            borrow_book.availbale = false;

            cout << "Book borrowed Successfully:" << user.getNameUser() << "\n";
        }

        else
        {
            cout << "Book borrowed not successfully\n";
        }
    }
};

int main()
{

    Library l1;
    l1.addBook();
    // l1.Display();
    l1.SearchBook(63);
    User u1;
    l1.borrow_book();

    return 0;
}