#include<stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day=01;
    ptrDate->month=01;
    ptrDate->year=2000;
};

void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date is: %d/%d/%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
};

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter date in dd/mm/yyyy format:\n");
    scanf("%d %d %d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
};


int main()
{
    struct Date d;
    int choice;
    
    do
    {
        printf("1.Initialize the date.\n2.Print date:\n3.Accept Date:\n4.Print Date After Accept: \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            initDate(&d);
            break;
        case 2:
            printDateOnConsole(&d);
            break;
        case 3:
            acceptDateFromConsole(&d);
            break;
        case 4:
            printDateOnConsole(&d);
            break;
        default:
            printf("Sorry! Please Choose correct option.\n");
            break;
        }


    printf("Press 0 to exit and non-zero to continue..");
    scanf("%d",&choice);
    } while (choice != 0);
    

    return 0;
}