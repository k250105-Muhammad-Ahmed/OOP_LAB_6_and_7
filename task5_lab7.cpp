#include <iostream>
#include <string>
using namespace std;

class Media
{
protected:
    string title;
    string publicationDate;
    int uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media(string t, string pDate, int id, string pub)
        : title(t), publicationDate(pDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo()
    {
        cout << "ID: " << uniqueID << endl;
        cout << "Title: " << title << endl;
        cout << "Released: " << publicationDate << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut()
    {
        if (!isCheckedOut)
        {
            isCheckedOut = true;
            cout << "Item " << title << " has been checked out successfully." << endl;
        }
        else
        {
            cout << "Sorry, " << title << " is already out." << endl;
        }
    }

    void returnItem()
    {
        isCheckedOut = false;
        cout << "Item '" << title << "' has been returned." << endl;
    }
    string getTitle() { return title; }
    string getPubDate() { return publicationDate; }
};

class Book : public Media
{
private:
    string author;
    string ISBN;
    int pages;

public:
    Book(string t, string pDate, int id, string pub, string auth, string isbn, int pg)
        : Media(t, pDate, id, pub), author(auth), ISBN(isbn), pages(pg) {}

    void displayInfo() override
    {
        cout << "[BOOK] " << endl;
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << pages << endl;
    }
};

class DVD : public Media
{
private:
    string director;
    int duration;
    string rating;

public:
    DVD(string t, string pDate, int id, string pub, string dir, int dur, string rat)
        : Media(t, pDate, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() override
    {
        cout << "[DVD]  " << endl;
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins " << endl;
        cout << "Rating: " << rating << endl;
    }
};

class LibraryManager
{
public:
    void search(Media *catalog[], int size, string queryTitle)
    {
        cout << "\nSearching for title: " << queryTitle << " " << endl;
        for (int i = 0; i < size; i++)
        {
            if (catalog[i]->getTitle() == queryTitle)
            {
                catalog[i]->displayInfo();
            }
        }
    }

    void search(Media *catalog[], int size, int queryID)
    {
        cout << "\nSearching for ID: " << queryID << " " << endl;
    }
};

int main()
{
    Media *catalog[3];
    catalog[0] = new Book("Peer-e-Kamil", "2004", 101, "Ferozsons", "Umera Ahmad", "978-01", 500);
    catalog[1] = new DVD("The Legend of Maula Jatt", "2022", 202, "Encyclomedia", "Bilal Lashari", 150, "13+");
    catalog[2] = new Book("Jannat Kay Pattay", "2012", 103, "Jhelum Publishers", "Nemrah Ahmed", "978-02", 650);

    cout << "\nNational Library Multimedia System " << endl;

    for (int i = 0; i < 3; i++)
    {
        catalog[i]->displayInfo();
        cout << endl;
    }
    LibraryManager manager;
    manager.search(catalog, 3, "Peer-e-Kamil");

    catalog[0]->checkOut();

    for (int i = 0; i < 3; i++)
    {
        delete catalog[i];
    }

    return 0;
}