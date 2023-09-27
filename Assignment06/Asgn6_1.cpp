#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void acceptDate()
    {
        cout << "Enter day:";
        cin >> day;
        cout << "Enter month:";
        cin >> month;
        cout << "Enter Year:";
        cin >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }

    void setDay(int day)
    {
        this->day = day;
    }

    void setMonth(int month)
    {
        this->month = month;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }
};

class Person
{
private:
    string name;
    string Address;
    Date dob;

public:
    Person()
    {
        this->name = "";
        this->Address = "";
    }

    Person(string name, string Address, int day, int month, int year) : dob(day, month, year)
    {

        this->name = name;
        this->Address = Address;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setAddress(string Address)
    {
        this->Address = Address;
    }

    void setDay(int day)
    {
        this->dob.setDay(day);
    }

    string getName()
    {
        return name;
    }

    string getAddress()
    {
        return Address;
    }

    int getDay()
    {
        return dob.getDay();
    }

    void displayPerson()
    {
        cout << "Name:" << name << endl;
        cout << "Address:" << Address << endl;
        cout << "Your birth Date is:";
        dob.displayDate();
    }

    void acceptPerson()
    {

        cout << "Enter Name:";
        cin >> name;
        cout << "Enter Address:";
        cin >> Address;
        cout << "Enter Dob in dd/mm/yyyy:";
        dob.acceptDate();
        cout << "**************************" << endl;
    }
};

class Employee
{
private:
    int id;
    float sal;
    string dept;
    Date doj;

public:
    Employee()
    {
        this->id = 0;
        this->sal = 0;
        this->dept = "";
    }

    Employee(int id, float sal, string dept, int day, int month, int year) : doj(day, month, year)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
    }

    void acceptEmp()
    {
        cout << "Enter Id:";
        cin >> id;
        cout << "Enter Salary:";
        cin >> sal;
        cout << "Enter Dept Name:";
        cin >> dept;
        cout << "Enter Joining Date:";
        doj.acceptDate();
    }

    void displayEmp()
    {
        cout << "Id is:" << id << endl;
        cout << "Salary:" << sal << endl;
        cout << "Dept is:" << dept << endl;
        cout << "Joining Date is:";
        doj.displayDate();
        cout << "**************************" << endl;
    }

    void setDeptName(string dept)
    {
        this->dept = dept;
    }

    void setSal(float sal)
    {
        this->sal = sal;
    }
};

int main()
{

    Person p;
    p.acceptPerson();
    p.displayPerson();
    Employee e;
    e.acceptEmp();
    e.displayEmp();

    return 0;
}