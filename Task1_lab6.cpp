#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string publisher;

    Book(string i_title, string i_author, string i_publisher) : title(i_title), author(i_author), publisher(i_publisher) {}
};

class FictionBook : public Book
{
private:
    string genre;
    string protagonist;

public:
    FictionBook(string i_genre, string i_prota, Book &sample) : Book(sample), genre(i_genre), protagonist(i_prota) {}
    void display()
    {
        cout << title << endl;
        cout << author << endl;
        cout << publisher << endl;
        cout << genre << endl;
        cout << protagonist << endl;
    }
};

int main()
{
    Book book("Helo", "Poke", "Capcom");
    FictionBook Fbook("Action", "Ash", book);

    Fbook.display();

    return 0;
}
