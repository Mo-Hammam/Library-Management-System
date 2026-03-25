#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Book
{
public:
    string author_book;
    string name_book;
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
};

class User
{
private:
    string name_user;

public:
    int id_user;
    vector<Book> borrowBooks;
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
        for (int i = 0; i < Books.size(); i++)
        {
            if (Books[i].id_book == b1.id_book)
            {

                cout << "❌ ID already exists! Try another ID\n";
                return;
            }
        }

        Books.push_back(b1);
        cout << "✅ Book Added Successfully\n";
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
            string path = "C:\\Users\\vip\\Desktop\\Library\\file.txt";
            ofstream file(path);

            file << "-------------------------------------\n";
            file << setw(5) << "ID" << setw(10) << "Name" << setw(10) << "Author" << setw(16) << "Available" << endl;
            file << "-------------------------------------\n";
            for (int i = 0; i < Books.size(); i++)
            {
                file << setw(5) << Books[i].id_book << setw(10) << Books[i].name_book
                     << setw(10) << Books[i].author_book << setw(10) << Books[i].availbale << endl;
                file << "-------------------------------------\n";
            }
            cout << "Done✅✅✅\n";
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
                    cout << setw(5) << Books[i].id_book << setw(10) << Books[i].name_book
                         << setw(10) << Books[i].author_book << setw(10) << Books[i].availbale << endl;
                    cout << "-------------------------------------\n";
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

    void borrow_book(Book &Book)

    {

        for (int j = 0; j < Books.size(); j++)
        {

            if (Books[j].availbale)
            {
                Books[j].availbale = false;
                User user11;
                user11.user_info();
                cout << "Book borrowed Successfully:" << user11.getNameUser() << "\n";
            }

            else
            {
                cout << "Book not  borrowed \n";
            }
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

    void Sort_Book()
    {

        int min;
        for (int i = 0; i < Books.size() - 1; i++)
        {
            min = i;
            for (int j = i + 1; j < Books.size(); j++)
            {
                if (Books[j].id_book < Books[min].id_book)
                {
                    min = j;
                }
            }
            swap(Books[min], Books[i]);
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
            cout << "\n_________START-MENU_________\n";
            cout << "1-ADD BOOK\n";
            cout << "2-DISPLAY BOOK\n";
            cout << "3-SEARCH BOOK\n";
            cout << "4-BORROW BOOK\n";
            cout << "5-RETURN BOOK\n";
            cout << "6-DELETE BOOK\n";
            cout << "7-SORT BOOK\n";
            cout << "8-Exit \n";

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
                        for (int i = 0; i < Books.size(); i++)
                        {
                            if (Books[i].id_book == id)
                            {
                                borrow_book(Books[i]);
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
                    Sort_Book();
                    cout << "The Books are Sorted✅✅✅\n";
                    break;
                }

                case 8:
                {
                    Exit_system();
                    break;
                }

                default:
                    cout << "Invaild ,Try Again\n";
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
