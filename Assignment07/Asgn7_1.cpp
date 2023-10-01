#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 01;
        this->month = 01;
        this->year = 1970;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
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
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }

    void acceptDate()
    {
        cout << "Enter Day:";
        cin >> day;
        cout << "Enter Month:";
        cin >> month;
        cout << "Enter Year:";
        cin >> year;
    }

    void displayDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Person
{
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
    string getName()
    {
        return this->name;
    }

    string getAddress()
    {
        return this->Address;
    }

    void setDate(Date dob)
    {
        this->dob = dob;
    }

    Date getDate()
    {
        return this->dob;
    }

    virtual void accept()
    {
        cout<<"Inside Person Accept"<<endl;
        cout<<"Enter Name:";
        cin>>name;
        cout<<"Enter Address:";
        cin>>Address;
        cout<<"Enter Your DOB:"<<endl;
        dob.acceptDate();
    }

    virtual void display()
    {
        cout<<"Inside Person Display"<<endl;
        cout<<"Name is:"<<name<<endl;
        cout<<"Address is:"<<Address<<endl;
        cout<<"Your DOB is:";
        dob.displayDate();
    }

};

class Employee:public Person
{
private:
    int id;
    float sal;
    string dept;
    Date doj;
public:
    Employee()
    {
        this->id=0;
        this->sal=0;
        this->dept="";
    }

    Employee(int id,float sal,string name,string Address,string dept,int day,int month,int year,int day1, int month1, int year1):doj(day,month,year),Person(name,Address,day1,month1,year1)//,Date doj)//:doj(day,month,year)
    {
        this->id=id;
        this->sal=sal;
        this->dept=dept;
        //this->setName(name);
        // this->setAddress(Address);
        // this->setDate(doj);
    }

    void accept()
    {
        cout<<"Inside Employee Accept"<<endl;
        Person::accept();
        cout<<"Enter Id:";
        cin>>id;
        cout<<"Enter Sal:";
        cin>>sal;
        cout<<"Enter Dept:";
        cin>>dept;
        cout<<"Enter DOJ";
        doj.acceptDate();
    }

    void display()
    {
        cout<<"Inside Employee Display"<<endl;
        cout<<"ID:"<<id<<endl;
        Person::display();
        // cout<<"Name:"<<getName()<<endl;
        cout<<"Salary:"<<sal<<endl;
        // cout<<"Address:"<<getAddress()<<endl;
        cout<<"Dept:"<<dept<<endl;
        cout<<"Your DOJ is:";
        // doj = getDate();
        doj.displayDate();
    }
};




int main()
{

    Person p1;
    p1.accept();
    p1.display();

    Person *p = new Employee;
    p->accept();
    p->display();
    // Date *d =  new Employee;
    // d.accept();
    // d.display();

    // Date doj;
    // cout<<"Enter Joining Date:";
    // doj.acceptDate();
    // // Person p;
    // // p.acceptPerson();
    // // p.displayPerson();


    // Employee e(1,2000,"HR","Firozabad","Engineer",01,01,2023,doj);
    // e.displayEmployee();
    
    return 0;
}