#include <iostream>
using namespace std;

class Product
{
    int id;
    string title;
    float price;
    char itemtype;

public:
    friend void discount(Product *arr[], int index);
    Product()
    {
        id = 0;
        title = "";
        price = 0;
        itemtype = '\0';
    }

    Product(int id, string title, float price, char itemtype)
    {
        this->id = id;
        this->title = title;
        this->price = price;
        this->itemtype = itemtype;
    }

    void setItemType(char itemtype)
    {
        this->itemtype = itemtype;
    }

    void setPrice(float price)
    {
        this->price = price;
    }

    float getPrice()
    {
        return this->price;
    }

    char getItemType()
    {
        return itemtype;
    }

    virtual void accept()
    {
        cout << "Enter Id:";
        cin >> id;
        cout << "Enter Title:";
        cin >> title;
        cout << "Enter Price:";
        cin >> price;
        // cout << "Enter Itemtype(B/T:(Book/Tape)):";
        // cin >> itemtype;
    }

    virtual void display()
    {

        cout << "Id:" << id << endl;
        cout << "Title:" << title << endl;
        cout << "Price:" << price << endl;
        cout << "Itemtype:" << itemtype << endl;
    }
};

class Book : public Product
{
    string author;

public:
    Book()
    {
        Product::setItemType('B');
    }
    void accept()
    {
        Product::accept();
        cout << "Enter Author:";
        cin >> author;
    }

    void display()
    {
        Product::display();
        cout << "Author is:" << author << endl;
    }
};

class Tape : public Product
{
    string artist;

public:
    Tape()
    {
        Product::setItemType('T');
    }
    void accept()
    {
        Product::accept();
        cout << "Enter Artist Name:";
        cin >> artist;
    }

    void display()
    {
        Product::display();
        cout << "Artist is:" << artist << endl;
    }
};

int menu()
{
    int choice;
    cout << "***********************************" << endl;
    cout << "0.EXIT." << endl;
    cout << "1.ADD_BOOK." << endl;
    cout << "2.ADD_TAPE." << endl;
    cout << "3.DISPLAY_BOOK." << endl;
    cout << "4.DISPLAY_TAPE." << endl;
    cout << "5.TOTAL_BILL." << endl;
    cout << "***********************************" << endl;
    cout << "Enter choice:";
    cin >> choice;

    return choice;
}
// discount(arr, ind, arr[i]->getItemType());

void discount(Product *arr[], int index)
{
    float tsum = 0, bsum = 0;
    for (int i = 0; i < index; i++)
    {
        if (arr[i]->itemtype == 'B')
        {
            bsum += (arr[i]->price - (arr[i]->price * 0.10));
        }
        if (arr[i]->itemtype == 'T')
        {
            tsum += (arr[i]->price - (arr[i]->price * 0.05));
        }
    }
    cout << "Total bill amount : " << tsum + bsum << endl;
}

int main()
{
    int choice;
    Product *arr[3];
    int ind = 0;
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            if (ind < 3)
            {
                arr[ind] = new Book();
                arr[ind]->accept();
                ind++;
            }
            else
            {
                cout << "Object is Full For Book;" << endl;
            }
            break;

        case 2:
            if (ind < 3)
            {
                arr[ind] = new Tape();
                arr[ind]->accept();
                ind++;
            }
            else
            {
                cout << "Object is Full For Tape;" << endl;
            }
            break;
        case 3:
            for (int i = 0; i < ind; i++)
            {
                if (arr[i]->getItemType() == 'B')
                {
                    arr[i]->display();
                }
            }
            break;
        case 4:
            for (int i = 0; i < ind; i++)
            {
                if (arr[i]->getItemType() == 'T')
                {
                    arr[i]->display();
                }
            }
            break;
        case 5:
            // int i;
            discount(arr, ind);
            break;

        default:
            cout << "Invalid choice...........";
            break;
        }
    }

    for (int i = 0; i < ind; i++)
    {
        delete arr[i];
    }

    cout << "Thank You For Using." << endl;

    return 0;
}