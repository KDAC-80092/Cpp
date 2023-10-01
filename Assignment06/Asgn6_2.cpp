#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    float sal;

protected:
    void setId(int id)
    {
        this->id = id;
    }

    void setSal(float sal)
    {
        this->sal = sal;
    }

    int getId()
    {
        return id;
    }

    float getSal()
    {
        return sal;
    }

public:
    Employee()
    {
        cout << "Inside Employee ctor" << endl;
        id = 0;
        sal = 0;
    }

    Employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }

    virtual void accept()
    {
        // cout << "Enter Employee Details:"<<endl;
        cout << "Enter Id:";
        cin >> id;
        cout << "Enter Sal:";
        cin >> sal;
    }

    virtual void display()
    {
        // cout << "Inside Employee" << endl;
        cout << "Id is:" << id << endl;
        cout << "Salary is:" << sal << endl;
    }
};

class Manager : virtual public Employee
{
private:
    float bonus;

protected:
    void accept_manager()
    {
        cout << "Enter Bonus:";
        cin >> bonus;
    }

    void display_manager()
    {
        // Employee::display();
        cout << "Bonus is:" << bonus<<endl;
    }

    void setBonus(float bonus)
    {
        this->bonus = bonus;
    }

    float getBonus()
    {
        return this->bonus;
    }

public:
    Manager()
    {
        cout << "Inside Manager ctor" << endl;
        this->bonus = 0.0;
    }

    Manager(int id, float sal, float bonus) : Employee(id, sal)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        cout<<"Enter Manager Details:"<<endl;
        Employee::accept();
        cout << "Enter Bonus:";
        cin >> bonus;
    }

    void display()
    {
        cout<<"Manager Details are:"<<endl;
        Employee::display();
        cout << "Bonus is:" << bonus << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    float comm;

protected:
    void accept_salesman()
    {
        cout << "Enter Commmission:";
        cin >> comm;
    }

    void display_salesman()
    {
        // Employee::display();
        cout << "Commission is:" << comm << endl;
    }

    void setComm(float comm)
    {
        this->comm = comm;
    }

    float getComm()
    {
        return this->comm;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman ctor" << endl;
        comm = 0;
    }

    Salesman(float comm, int id, float sal) : Employee(id, sal)
    {
        this->comm = comm;
    }

    void accept()
    {
        cout<<"Enter Salesman Details:"<<endl;
        Employee::accept();
        cout << "Enter Commmission:";
        cin >> comm;
    }

    void display()
    {
        cout<<"Salesman Details are:"<<endl;
        Employee::display();
        cout << "Commission is:" << comm << endl;
    }
};

class salesManager : public Manager, public Salesman
{
public:
    salesManager()
    {
        cout << "Inside Sales_manager ctor" << endl;
    }
    salesManager(int id, float sal, float bonus, float comm)
    {
        this->setId(id);
        this->setSal(sal);
        this->setBonus(bonus);
        this->setComm(comm);
    }

    void accept()
    {
        cout<<"Enter Salesman_Manager Details:"<<endl;
        Employee::accept();
        Manager::accept_manager();
        Salesman::accept_salesman();
    }

    void display()
    {
        cout<<"Salesman_Manager Details are:"<<endl;
        Employee::display();
        Manager::display_manager();
        Salesman::display_salesman();
    }
};

int main()
{
    Manager m;
    m.accept();
    m.display();

    // Employee *e = new salesManager;
    // e->accept();
    // e->display();
    // salesManager s;
    // s.accept();
    // s.display();

    return 0;
}
