#include <iostream>
using namespace std;

class Student
{
    int rollNumber;
    // static int generateRollNumber;
    char gender;
    string name;
    float m1, m2, m3;

public:
    Student()
    {
        this->gender = '\0';
        this->name = "";
        rollNumber++;
    }

    Student(char gender, string name, float m1, float m2, float m3)
    {
        this->gender = gender;
        this->name = name;
        this->m1 = m1;
        this->m2 = m2;
        this->m3 = m3;
        // rollNumber++;
    }

    void accept()
    {
        cout << "Enter Name:";
        cin >> name;
        cout << "Enter Gender(M/F):";
        cin >> gender;
        cout << "Enter marks of three subjects:";
        cin >> m1 >> m2 >> m3;
        cout<<"Enter roll Number:"<<endl;
        cin>>rollNumber;
    }

    void display()
    {
        cout << "Roll Number is:" << rollNumber << endl;
        cout << "Name is:" << this->name << endl;
        cout << "Gender is:" << this->gender << endl;
        cout << "Percentage is:" << (m1 + m3 + m3) / 3 << endl;
    }

    int getRollNumber()
    {
        return this->rollNumber;
    }
};

// int Student::rollNumber=0;

int menu()
{
    int choice;
    cout << "************************************************" << endl;
    cout << "0.EXIT" << endl;
    cout << "1.Enter details of student." << endl;
    cout << "2.Search for Student Via Roll Number." << endl;
    cout << "3.Sort Students." << endl;
    cout << "4.Display Student Details." << endl;
    cout << "************************************************" << endl;

    cout << "Enter choice:" << endl;
    cin >> choice;

    return choice;
}

int searchStudent(Student arr[], int index, int checkroll)
{
    for (int i = 0; i < index; i++)
    {
        if (arr[i].getRollNumber() == checkroll)
        {
            return i;
        }
    }  
    return -1;
}

void sortStudents(Student arr[], int index)
{
    for (int i = 0; i < index - 1; i++)
    {
        for (int j = 0; j < index - i - 1; j++)
        {
            if (arr[j].getRollNumber() > arr[j + 1].getRollNumber())
            {
                // Swap arr[j] and arr[j+1]
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// int Student::generateRollNumber = 0;

int main()
{
    Student arr[5];
    int index = 0;
    int choice;

    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (index < 5)
            {
                arr[index].accept();
                index++;
            }
            else
            {
                cout << "Full."<<endl;
            }
            break;

        case 2:
            cout << "Enter the Roll Number To check." << endl;
            int x;
            cin >> x;
            int ct;

            ct = searchStudent(arr, index, x);

            if (ct == 0)
            {
                cout << "Record Not Found." << endl;
            }

            else
            {
                arr[ct].display();
            }
            break;
        case 3:
            sortStudents(arr,index);
            break;
        case 4:
            for (int i = 0; i < index; i++)
            {
                arr[i].display();
            }
            break;

        default:
            cout << "Wrong Choice....................)";
            break;
        }
    }

    return 0;
}