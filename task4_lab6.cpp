#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string i_name, int i_age) : name(i_name), age(i_age) {}

    virtual void display() const
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
    }
};

class Student : virtual public Person
{
protected:
    int ID;
    char gradeLevel;

public:
    Student(string i_name, int i_age, int id, char grade) : ID(id), gradeLevel(grade), Person(i_name, i_age) {}
    int getID() { return ID; }
    char getGrade() { return gradeLevel; }

    void display() const override
    {
        Person::display();
        cout << "ID:" << ID << endl;
        cout << "Grade Level:" << gradeLevel << endl;
    }
};

class Teacher : virtual public Person
{
protected:
    string subject;
    int roomNumber;

public:
    Teacher(const string &i_name, int i_age, const string &i_subject, int i_roomNumber) : subject(i_subject), roomNumber(i_roomNumber), Person(i_name, i_age) {}

    string getSubject() { return subject; }
    int getRoomNumber() { return roomNumber; }

    void display() const override
    {
        Person::display();
        cout << "Subject:" << subject << endl;
        cout << "Room Number:" << roomNumber << endl;
    }
};

class GraduateStudent : public Student, public Teacher
{
public:
    GraduateStudent(const string &i_name, int i_age, int id, char grade, const string &i_subject, int i_roomNumber) : Person(i_name, i_age), Student(i_name, i_age, id, grade), Teacher(i_name, i_age, i_subject, i_roomNumber) {}

    void display() const override
    {
        Person::display();
        cout << "ID:" << ID << endl;
        cout << "Grade Level:" << gradeLevel << endl;
        cout << "Subject:" << subject << endl;
        cout << "Room Number:" << roomNumber << endl;
    }
};

int main()
{
    GraduateStudent gs("Ali", 25, 1234, 'A', "Computer Science", 101);
    gs.display();
    return 0;
}