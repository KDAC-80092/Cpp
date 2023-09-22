#include<iostream>
using namespace std;
class Address
{
    private:
        string building;
        string street;
        string city;
        int pin;

    public:

        Address()
        {
            this->building="Sunbeam";
            this->street="Shaniwar Peth";
            this->city="Karad";
            this->pin=455110;
        }

        Address(string b,string s,string c,int p)
        {
            this->building=b;
            this->street =s;
            this->city=c;
            this->pin =p;
        }

        void accept()
        {
            cout<<"Enter Bulding,street,city and pin:"<<endl;
            cin>>this->building>>this->street>>this->city>>this->pin;
        }

        void display()
        {
            cout<<"Building:"<<this->building<<endl<<"Street:"<<this->street<<endl;
            cout<<"City:"<<this->city<<endl<<"Pin Code:"<<this->pin<<endl;
        }

        void setBuilding(string building)
        {
            this->building=building;
        }
        void setStreet(string Street)
        {
            this->street=Street;
        }
        void setCity(string city)
        {
            this->city=city;
        }
        void setPin(int pin)
        {
            this->pin=pin;
        }

        string getBuilding()
        {
            return this->building;
        }
        string getStreet()
        {
            return this->street;
        }
        string getCity()
        {
            return this->city;
        }
        int getPin()
        {
            return this->pin;
        }



};

int main()
{
    Address a1;
    Address a2("Nehru Nagar","Road","Agra",283203);
    a2.display();
    a1.accept();
    a1.display();
    a1.setBuilding("Client");
    cout<<a1.getBuilding()<<endl;
    a2.getCity();
    a2.setCity("Pune");


    return 0;
}