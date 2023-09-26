#include <iostream>
using namespace std;

class tollBooth
{
private:
    unsigned t_cars;
    unsigned t_money;

public:
    tollBooth()
    {
        this->t_cars = 0;
        this->t_money = 0;
    }

    void payingCars()
    {
        this->t_cars = t_cars + 1;
        this->t_money = t_money + 50;
    }

    void nopayCars()
    {
        this->t_cars = t_cars + 1;
    }

    void printOnConsole()
    {
        cout << "Total Cars are:" << t_cars << endl;
        cout << "Total Amount Received:" << t_money << endl;
        cout << "Cars which pays the toll:" << t_money / 50 << endl;
        cout << "Cars with non-paying Toll are:" << t_cars - (t_money / 50) << endl;
    }
};

int menu()
{
    int choice;
    cout << "******************************" << endl;
    cout << "0.EXIT." << endl;
    cout << "1.Paying Cars." << endl;
    cout << "2.Non-Paying Cars." << endl;
    cout << "3.Print For Total." << endl;
    cout << "******************************" << endl;
    cin >> choice;
    return choice;
}

int main()
{
    tollBooth b;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            b.payingCars();
            break;

        case 2:
            b.nopayCars();
            break;
        case 3:
            b.printOnConsole();
            break;

        default:
            cout << "Invalid! Choice, Please Choose Correct Option...";
            break;
        }
    }

    cout << "Thanks For Using Our app.........)" << endl;

    return 0;
}