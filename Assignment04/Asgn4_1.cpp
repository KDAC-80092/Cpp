#include <iostream>

using namespace std;

class Time
{
private:
    int h;
    int m;
    int s;

public:
    Time()
    {
        h = 00;
        m = 00;
        s = 00;
    }

    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }

    void setHour(int h)
    {
        this->h = h;
    }

    void setMinute(int m)
    {
        this->m = m;
    }

    void setSeconds(int s)
    {
        this->s = s;
    }

    int getHour()
    {
        return h;
    }

    int getMinute()
    {
        return m;
    }
    int getSeconds()
    {
        return s;
    }

    void printTime()
    {
        cout << "Time is- " << h << ":" << m << ":" << s << endl;
    }
};

int main()
{
    int n;
    cout << "Enter size:";
    cin >> n;

    // Creating Pointers Of Array.
    // Time *arr[n];

    // For parameterless constructor.

    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = new Time();
    // }

    // Array Of Dynamic Objects.

    // for (int i = 0; i < n; i++)
    // {
    //     int h, m, s;
    //     cout << "Enter HH:MM::SS-> ";
    //     cin >> h >> m >> s;
    //     arr[i] = new Time(h, m, s);
    // }

    // dynamic memory allocation for objects and insert values, Dynammic Array Of Dynamic Objects, Initialize Using Parameterized Constructor.
    Time **arr = new Time *[n];
    for (int i = 0; i < n; i++)
    {
        int h, m, s;
        cout << "Enter HH:MM::SS-> ";
        cin >> h >> m >> s;
        arr[i] = new Time(h, m, s);
    }

    // Using Mutator/Setter Taking Input.

    for (int i = 0; i < n; i++)
    {
        int h, m, s;
        cout << "Set Hour:" << endl;
        cin >> h;
        arr[i]->setHour(h);
        cout << "Set Minute:" << endl;
        cin >> m;
        arr[i]->setMinute(m);
        cout << "Set Seconds:" << endl;
        cin >> s;
        arr[i]->setSeconds(s);
    }

    // Using Inspector/Getter To Get the values.

    for (int i = 0; i < n; i++)
    {
        cout << "Hour is:" << arr[i]->getHour() << endl;
        cout << "Minutes is:" << arr[i]->getMinute() << endl;
        cout << "Second is:" << arr[i]->getSeconds() << endl;
    }

    // displaying the objects
    for (int i = 0; i < n; i++)
    {
        arr[i]->printTime();
    }

    // deallocating the objects memory
    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }

    delete[] arr;

    return 0;
}