#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int ID;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, int id, string addr, string phone, string e)
        : name(n), ID(id), address(addr), phoneNumber(phone), email(e) {}

    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    void updateInfo()
    {
        int choice;
        cout << "\n1. Name\n2. ID\n3. Address\n4. Phone\n5. Email\nSelect field: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "New Name: ";
            getline(cin, name);
        }
        else if (choice == 2)
        {
            cout << "New ID: ";
            cin >> ID;
        }
        else if (choice == 3)
        {
            cout << "New Address: ";
            getline(cin, address);
        }
        else if (choice == 4)
        {
            cout << "New Phone: ";
            getline(cin, phoneNumber);
        }
        else if (choice == 5)
        {
            cout << "New Email: ";
            getline(cin, email);
        }
    }
};

class Student : public Person
{
private:
    string currentCourse;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, int id, string addr, string p, string e, double i_gpa, int year)
        : Person(n, id, addr, p, e), GPA(i_gpa), enrollmentYear(year)
    {
        currentCourse = "None";
    }

    void setCourse(string cName)
    {
        currentCourse = cName;
    }

    void displayInfo() override
    {
        cout << "\nStudent Record" << endl;
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Current Course: " << currentCourse << endl;
    }
};

class Professor : public Person
{
private:
    string department;
    string coursesTaught;
    double salary;

public:
    Professor(string n, int id, string addr, string p, string e, string dept, double sal)
        : Person(n, id, addr, p, e), department(dept), salary(sal)
    {
        coursesTaught = "C++ Programming";
    }

    void displayInfo() override
    {
        cout << "\nFaculty Record" << endl;
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Teaching: " << coursesTaught << endl;
    }
};

class Staff : public Person
{
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, int id, string addr, string p, string e, string dept, string pos, double sal)
        : Person(n, id, addr, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() override
    {
        cout << "\nAdministrative Record " << endl;
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Monthly Salary: $" << salary << endl;
    }
};

class Course
{
private:
    string courseId;
    string courseName;
    int credits;
    string instructor;

public:
    Course(string id, string name, int cred, string instr)
        : courseId(id), courseName(name), credits(cred), instructor(instr) {}

    void registerStudent(Student &s)
    {
        s.setCourse(this->courseName);
        cout << "Registration successful for " << courseName << endl;
    }

    void calculateGrades()
    {
        cout << "Generating grade reports for " << courseId << "..." << endl;
    }
};

int main()
{

    Student s1("Ahmed Khan", 2024101, "Sector H-12, Islamabad", "0300-1234567", "ahmed.k@nust.edu.pk", 3.5, 2024);

    Professor p1("Dr. Sarah Ali", 5002, "DHA Phase 6, Lahore", "0332-35559999", "sarah.ali@fast.nu.edu.pk", "Computer Science", 250000.00);

    Staff st1("Zubair Ahmed", 9005, "P.E.C.H.S, Karachi", "0333-9876543", "zubair.admin@uet.edu.pk", "Registrar Office", "Senior Clerk", 75000.00);

    Course c1("CS201", "Data Structures", 4, "Dr. Sarah Ali");

    cout << "\nUniversity Management System " << endl;

    c1.registerStudent(s1);

    s1.displayInfo();
    p1.displayInfo();
    st1.displayInfo();

    s1.updateInfo();

    cout << "\nUpdated Student Record" << endl;
    s1.displayInfo();
    return 0;
}