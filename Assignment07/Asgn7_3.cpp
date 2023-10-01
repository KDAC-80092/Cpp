#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    float sal;
    string designation;

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

    void setDesignation(string designation)
    {
        this->designation = designation;
    }

public:
    Employee()
    {
        // cout << "Inside Employee ctor" << endl;
        id = 0;
        sal = 0;
    }

    Employee(int id, float sal)
    {
        this->id = id;
        this->sal = sal;
    }

    string getDesignation()
    {
        return this->designation;
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
        cout << "Bonus is:" << bonus << endl;
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
        // cout << "Inside Manager ctor" << endl;
        Employee::setDesignation("Manager");
        this->bonus = 0.0;
    }

    Manager(int id, float sal, float bonus) : Employee(id, sal)
    {
        this->bonus = bonus;
    }

    void accept()
    {
        cout << "Enter Manager Details:" << endl;
        Employee::accept();
        cout << "Enter Bonus:";
        cin >> bonus;
    }

    void display()
    {
        cout << "Manager Details are:" << endl;
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
        // cout << "Inside Salesman ctor" << endl;
        Employee::setDesignation("Salesman");
        comm = 0;
    }

    Salesman(float comm, int id, float sal) : Employee(id, sal)
    {
        this->comm = comm;
    }

    void accept()
    {
        cout << "Enter Salesman Details:" << endl;
        Employee::accept();
        cout << "Enter Commmission:";
        cin >> comm;
    }

    void display()
    {
        cout << "Salesman Details are:" << endl;
        Employee::display();
        cout << "Commission is:" << comm << endl;
    }
};

class salesManager : public Manager, public Salesman
{
public:
    salesManager()
    {
        // cout << "Inside Sales_manager ctor" << endl;
        Employee::setDesignation("SalesManager");
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
        cout << "Enter Salesman_Manager Details:" << endl;
        Employee::accept();
        Manager::accept_manager();
        Salesman::accept_salesman();
    }

    void display()
    {
        cout << "Salesman_Manager Details are:" << endl;
        Employee::display();
        Manager::display_manager();
        Salesman::display_salesman();
    }
};

enum EMenu
{
    EXIT,
    ADD_MANAGER,
    ADD_SALESMAN,
    ADD_SALES_MANAGER,
    DISPLAY_COUNT_DESIGNATION,
    DISPLAY_MANAGER,
    DISPLAY_SALESMAN,
    DISPLAY_SALES_MANAGER,
    DISPLAY_ALL
};

int menu()
{

    int choice;
    cout << "******************************" << endl;
    cout << "0.EXIT." << endl;
    cout << "1.ADD_MANAGER." << endl;
    cout << "2.ADD_SALESMAN." << endl;
    cout << "3.ADD_SALESMANAGER." << endl;
    cout << "4.DISPLAY COUNT OF ALL EMPLOYESS DESIGNATION WISE." << endl;
    cout << "5.DISPLAY MANAGERS." << endl;
    cout << "6.DISPLAY SALESMAN." << endl;
    cout << "7.DISPLAY SALESMANAGER." << endl;
    cout << "8.DISPLAY ALL EMPLOYEES." << endl;
    cout << "******************************" << endl;
    cout << "Enter Choice:";
    cin >> choice;

    return choice;
}

// Global Function To Count Number Of Employees
void employeeCount(Employee *e[], int index)
{
    int mCount = 0, sCount = 0, smCount = 0;
    if (index == 0)
    {
        cout << "Employess Details Not Available." << endl;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            if (e[i]->getDesignation() == "Manager")
            {
                mCount++;
            }

            else if (e[i]->getDesignation() == "Salesman")
            {
                sCount++;
            }

            else if (e[i]->getDesignation() == "SalesManager")
            {
                smCount++;
            }
        }
    }
    cout << "--------Total Employees Designation Wise----------" << endl;
    cout << "Manager Count is:" << mCount << endl;
    cout << "Salesman Count is:" << sCount << endl;
    cout << "Sales_Manager Count is:" << smCount << endl;
    cout << "Total Number of Employees are:" << index << endl;
}

// Global Function To Display Manager
void displayManagerDetails(Employee *e[], int index)
{
    for (int i = 0; i < index; i++)
    {
        if (e[i]->getDesignation() == "Manager")
        {
            cout << "Manager's:" << endl;
            cout << "*********************************" << endl;
            e[i]->display();
            cout << "*********************************" << endl;
        }
    }
}

// Global Function To Display SalesMan
void displaySalesmanDetails(Employee *e[], int index)
{
    for (int i = 0; i < index; i++)
    {
        if (e[i]->getDesignation() == "Salesman")
        {
            cout << "Salesman's:" << endl;
            cout << "*********************************" << endl;
            e[i]->display();
            cout << "*********************************" << endl;
        }
    }
}

// Global Function To Display SalesManager
void displaySalesManagerDetails(Employee *e[], int index)
{
    for (int i = 0; i < index; i++)
    {
        if (e[i]->getDesignation() == "SalesManager")
        {
            cout << "SalesManager's:" << endl;
            cout << "*********************************" << endl;
            e[i]->display();
            cout << "*********************************" << endl;
        }
    }
}

// Global Function to Display All Employees Designation Wise
void displayAllEmployees(Employee *e[], int index)
{
    cout << "-----------------------Display All Employees--------------------------------" << endl;
    if (index == 0)
    {
        cout << "Employess Details Not Available." << endl;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            if (e[i]->getDesignation() == "Manager")
            {
                cout << "Managers:" << endl;
                cout << "*********************************" << endl;
                e[i]->display();
                cout << "*********************************" << endl;
            }

            else if (e[i]->getDesignation() == "Salesman")
            {
                cout << "Salesmans:" << endl;
                cout << "*********************************" << endl;
                e[i]->display();
                cout << "*********************************" << endl;
            }

            else if (e[i]->getDesignation() == "SalesManager")
            {
                cout << "SalesManagers:" << endl;
                cout << "*********************************" << endl;
                e[i]->display();
                cout << "*********************************" << endl;
            }
        }
    }
}

int main()
{
    // int size;
    // cout << "Enter size of Array:";
    // cin >> size;
    // Employee *e[size];
    Employee *ee[10];
    int choice1;
    int index = 0;

    while ((choice1 = menu()) != EXIT)
    {
        switch (choice1)
        {
        case ADD_MANAGER:
            if (index < 10)
            {
                ee[index] = new Manager();
                ee[index]->accept();
                index++;
            }
            else
            {
                cout << "Positions are Full for Manager." << endl;
            }
            break;
        case ADD_SALESMAN:
            if (index < 10)
            {
                ee[index] = new Salesman();
                ee[index]->accept();
                index++;
            }
            else
            {
                cout << "Positions are Full for Salesman." << endl;
            }
            break;

        case ADD_SALES_MANAGER:
            if (index < 10)
            {
                ee[index] = new salesManager();
                ee[index]->accept();
                index++;
            }
            else
            {
                cout << "Positions are Full for Sales Manager." << endl;
            }
            break;

        case DISPLAY_COUNT_DESIGNATION:
            employeeCount(ee, index);
            break;

        case DISPLAY_MANAGER:
            displayManagerDetails(ee, index);
            break;

        case DISPLAY_SALESMAN:
            displaySalesmanDetails(ee, index);
            break;

        case DISPLAY_SALES_MANAGER:
            displaySalesManagerDetails(ee, index);
            break;

        case DISPLAY_ALL:
            displayAllEmployees(ee, index);
            break;

        default:

            cout
                << "Wrong! Choice:...................." << endl;
            break;
        }
    }

    for (int i = 0; i < index; i++)
    {
        delete ee[i];
    }

    cout << "Thank You for Using Our App............:)" << endl;

    return 0;
}
