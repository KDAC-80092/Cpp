#include <iostream>
using namespace std;

class Employee
{
private:
    int id = 1;
    float sal = 2000;

public:
    Employee()
    {
        cout << "Inside Employee ctor" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    float bonus = 500;

public:
    Manager()
    {
        cout << "Inside Manager ctor" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    float comm = 0.10;

public:
    Salesman()
    {
        cout << "Inside Salesman ctor" << endl;
    }
};

class salesManager : public Manager, public Salesman
{
public:
    salesManager()
    {
        cout << "Inside Sales_manager ctor" << endl;
    }
};

int main()
{
    salesManager s;

    return 0;
}
