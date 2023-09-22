#include<iostream>
using namespace std;

class student
{
    private:
        int rollno;
        string name;
        int marks;

    public:

        void initStudent()
        {
            rollno=21;
            name = "Krishna";
            marks = 100;
        }

        void printStudentOnConsole()
        {
            cout<<"Rollno:"<<rollno<<endl<<"Name:"<<name<<endl<<"Marks:"<<marks;
        }

        void acceptStudentFromConsole()
        {
            cout<<"Enter rollno,name,marks:-";
            cin>>rollno>>name>>marks;
        }
};


int main()
{
    student s;
    int choice;

    do
    {
        cout<<"Enter Choice:\n1.Initialize Student Info:\n2.Print Data On Console:\n3.Accept Student Info:\n4.Print Student Info:\n"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            s.initStudent();
            break;
        case 2:
            s.printStudentOnConsole();
            break;
        case 3:
            s.acceptStudentFromConsole();
            break;
        case 4:
            s.printStudentOnConsole();
            break;    
        
        default:
            cout<<"Sorry! Invalid operation."<<endl;
            break;
        }
        cout<<"\nPress 0 to exit and non-zero to continue..";
        cin>>choice;
    }while (choice!=0);

    return 0;

}