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
    }
    // void displayBook()
    // {
    //     cout << "-------------------------------------\n";
    //     cout << setw(10) << "The Book of ID:" << setw(5) << id_book << endl;
    //     cout << "-------------------------------------\n";
    //     cout << setw(10) << "The Book of Name:" << setw(5) << name_book << endl;
    //     cout << "-------------------------------------\n";
    //     cout << setw(10) << "The Book of Author:" << setw(5) << author_book << endl;
    //     cout << "-------------------------------------\n";
    // }
    void displayBook()
    {

        cout << setw(5) << id_book << setw(10) << name_book << setw(10) << author_book << setw(10) << availbale << endl;
        cout << "-------------------------------------\n";
        // cout << "-------------------------------------\n";
        // cout << setw(5) << "The Book of Name:" << setw(5) << name_book << endl;
        // cout << "-------------------------------------\n";
        // cout << setw(5) << "The Book of Author:" << setw(5) << author_book << endl;
        // cout << "-------------------------------------\n";
    }
};

class User
{
private:
    int id_user;
    string name_user;

public:
    void user_info()
    {
        cout << "Enter UserID:";
        cin >> id_user;
        cout << endl;
        cout << "Enter UserName: ";
        cin >> name_user;
    }

    string getNameUser()
    {
        return name_user;
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

    void DisplayBook()
    {

        if (Books.empty())
        {

            cout << "No Books Found❗❗❗❗\n";
            return;
        }
        else
        {
            cout << "-------------------------------------\n";
            cout << setw(5) << "ID" << setw(10) << "Name" << setw(10) << "Author" << setw(16) << "Available" << endl;
            cout << "-------------------------------------\n";
            for (int i = 0; i < Books.size(); i++)
            {
                Books[i].displayBook();
            }
        }
    }
    void SearchBook(int bookSearch)
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
                if (Books[i].id_book == bookSearch)
                {
                    cout << "✅✅✅\n";
                    cout << "The Book is Found\n";
                    cout << "✅✅✅\n";
                    Books[i].displayBook();
                }
                else
                {
                    cout << "❗❗❗❗\n";
                    cout << "This Book isn't Found\n";
                    cout << "❗❗❗❗\n";
                    return;
                }
            }
        }
    }

    void borrow_book(Book &borrow_book, User &user)

    {

        if (borrow_book.availbale)
        {
            borrow_book.availbale = false;

            user.user_info();
            cout << "Book borrowed Successfully:" << user.getNameUser() << "\n";
        }

        else
        {
            cout << "Book not  borrowed \n";
        }
    }

    void Return_book(int id)
    {
        bool falg = false;
        for (int i = 0; i < Books.size(); i++)
        {
            if (Books[i].id_book == id)
            {
                falg = true;
                if (Books[i].availbale == false)
                {

                    Books[i].availbale = true;
                    cout << "Book is available Now\n";
                }
                else
                {
                    cout << "Book isn't available Now\n";
                }
                break;
            }
        }
        if (!falg)
            cout << "Book is Found❕❕❕\n";
    }

    void Delete_book(int id)
    {

        if (Books.empty())
        {

            cout << "NO Books in Library\n";
            return;
        }
        else
        {

            for (int i = 0; i < Books.size(); i++)
            {
                if (Books[i].id_book == id)
                {
                    Books.erase(Books.begin() + i);
                    cout << "Book deleted\n";
                    return;
                }
            }
        }
    }

    void Exit_system()
    {
        exit(0);
    }

    void start()
    {

        int choice;
        while (true)
        {
            cout << "/n_________START-MENU_________\n";
            cout << "1-ADD BOOK\n";
            cout << "2-DISPLAY BOOK\n";
            cout << "3-SEARCH BOOK\n";
            cout << "4-BORROW BOOK\n";
            cout << "5-RETURN BOOK\n";
            cout << "6-DELETE BOOK\n";
            cout << "7-Exit \n";

            cout << "Enter Your Choice:";
            cin >> choice;
            if (cin.fail())
            {
                cout << "invalid Choice❌❌❌\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else

            {
                switch (choice)
                {
                case 1:
                    addBook();
                    break;

                case 2:
                    DisplayBook();
                    break;

                case 3:

                    int bookSearch;
                    cout << "Enter the ID of Book to Search it:";
                    cin >> bookSearch;
                    SearchBook(bookSearch);
                    break;
                case 4:

                {
                    if (Books.empty())
                    {

                        cout << "NO Books in Library❓❓❓\n";
                        cout << "PLEASE ADD BOOKS\n";
                        break;
                    }
                    else
                    {

                        int id;
                        cout << "Enter Book ID:";
                        cin >> id;
                        User user_1;
                        for (int i = 0; i < Books.size(); i++)
                        {
                            if (Books[i].id_book == id)
                            {
                                borrow_book(Books[i], user_1);
                            }
                        }
                        break;
                    }
                }
                case 5:
                {
                    int id;
                    cout << "Enter the Book ID:";
                    cin >> id;
                    Return_book(id);
                    break;
                }
                case 6:
                {
                    int id;
                    cout << "Enter Book id:";
                    cin >> id;
                    Delete_book(id);
                    break;
                }
                case 7:
                {
                    Exit_system();
                    break;
                }

                default:
                    cout << "Invaild ,Try Again";
                    break;
                }
            }
        }
    }
};

int main()
{

    Library l1;

    l1.start();

    return 0;
}
