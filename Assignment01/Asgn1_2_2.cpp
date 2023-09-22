#include<iostream>
using namespace std;

class Date
{
   private:
        int day;
        int month;
        int year;

    public:

        void initDate()
        {
            day = 01;
            month =01;
            year = 2000;
        }

        void printDateOnConsole()
        {
            cout<<"Date is:"<<day<<"/"<<month<<"/"<<year<<endl;
        }

        void acceptDateFromConsole()
        {
            cout<<"\nEnter date in dd//mm/yyyy format:";
            cin>>day>>month>>year;
        }

        bool isLeapYear()
        {
            return ((year%4 == 0 && year%100 != 0) || (year%4==0)); 
        }

};

int main()
{
    bool y = true;
    int choice;
    Date d;

    do
    {
        cout<<"1.Initialize Date:\n2.Print Date On Console:\n3.Accept Date:\n4.Check Leap:\n5.Print Date After Accept:\n"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            d.initDate();
            break;
        case 2:
            d.printDateOnConsole();
            break;
        case 3:
            d.acceptDateFromConsole();
            break;
        case 4:
            if(d.isLeapYear())
            {
                cout<<"\n"<<" Is a leap Year."<<endl;
            }
            else
            {
                cout<<"\n"<<" Is not a Leap Year."<<endl;
            }
            break;
        case 5:
            d.printDateOnConsole();
            break;    
        
        default:
            cout<<"Sorry! Invalid operation."<<endl;
            break;
        }
        cout<<"Press 0 to exit and non-zero to continue..";
        cin>>choice;
    }while (choice!=0);
    
    

    return 0;
}