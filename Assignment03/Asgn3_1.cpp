#include<iostream>

using namespace std;

class Box
{
    private:
        float length;
        float width;
        float height;

    public:

        Box()
        {
            this->length=1;
            this->width=1;
            this->height=1;
        }

        void acceptValue()
        {
            cout<<"Length: ";
            cin>>this->length;
            cout<<"Width: ";
            cin>>this->width;
            cout<<"Height: ";
            cin>>this->height;
        }

        void displayVolume()
        {
            cout<<"Volume of the Box is:"<<length*width*height<<endl;
        }
};

int menu()
{
    int choice;
    cout<<"************************************"<<endl;
    cout<<"0.EXIT"<<endl;
    cout<<"1.Input Data:"<<endl;
    cout<<"2.Display Volume:"<<endl;
    cout<<"************************************"<<endl;
    cout<<"Enter Choice:";
    cin>>choice;
    return choice;
}

int main()
{
    Box b;
    int choice;
    while ((choice = menu())!=0)
    {
        switch (choice)
        {
        case 1:
            b.acceptValue();
            break;
        case 2:
            b.displayVolume();
            break;

        
        default:
            cout<<"Invalid! Choice, Please select correct option...("<<endl;
            break;
        }
    }
    
    cout<<"Thank You For Using Our App."<<endl;
    return 0;
}