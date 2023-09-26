#include "./cylinder.h"
#include "./menu.h"


int main()
{

    float r, h;
    int choice;
    Cylinder c;
    while ((choice = menu()) != EXIT)
    {
        switch (choice)
        {
        case ACCEPT_RADIUS:
            cout << "Enter Radius:";
            cin >> r;
            c.setRadius(r);
            break;

        case ACCEPT_HEIGHT:
            cout << "Enter Height:";
            cin >> h;
            c.setHeight(h);
            break;

        case GET_RADIUS:
            cout << "Radius is:" << c.getRadius() << endl;
            break;

        case GET_HEIGHT:
            cout << "Height is:" << c.getHeight()<<endl;
            break;
            
        case PRINT_VOLUME:
            c.printVolume();
            break;

        default:
            cout << "Sorry! Invalid CHOICE, Please CHoose Correct Option......(^^)" << endl;
            break;
        }
    }

    cout << "Thank You For Using Our App....>)" << endl;

    return 0;
}