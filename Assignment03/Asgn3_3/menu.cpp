#include "./menu.h"
#include<iostream>
using namespace std;

EMenu menu()
{
    int choice;
    cout << "*************************************" << endl;
    cout << "0.EXIT" << endl;
    cout << "1.Input Radius." << endl;
    cout << "2.Input Height." << endl;
    cout << "3.See Radius." << endl;
    cout << "4.See Height." << endl;
    cout << "5.Print Volume." << endl;
    cout << "*************************************" << endl;
    cout << "Enter Choice:";
    cin >> choice;

    return EMenu(choice);
}