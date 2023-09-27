#include <iostream>
using namespace std;
#define SIZE 5


class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        this->top = -1;
        if (size != 0)
        {
            this->arr = new int[size];
            this->size = size;
        }
        else
        {
            this->arr = new int[SIZE];
            this->size = 5;
        }
    }

    void push(int a)
    {
        if(this->top == this->size-1)
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            this->top++;
            this->arr[top]=a;
        }

    }

    void pop()
    {
        if(this->top==-1)
            cout<<"Stack is Empty"<<endl;
        else
        {
            this->arr[top]=0;
            top--;
        }
    }

    void peek()
    {
        if (this->top==-1)
        {
            cout<<"Stack is empty"<<endl;

        }
        else
        {
            cout<<"Peeked Value is:"<<this->arr[top]<<endl;

        }
    }

    void isEmpty()
    {
        if(this->top==-1)
            cout<<"Stack is Empty"<<endl;
        else    
            cout<<"Stack is not Empty"<<endl;
    }

    void isFull()
    {
        if(this->top==(this->size)-1)
            cout<<"Stack is Full"<<endl;
        else    
            cout<<"Stack is Empty:"<<endl;
    }

    ~Stack()
    {
        cout<<"Inside DTOR";
        delete[] arr;
    }
};

int main()
{

    int size;
    cout<<"Enter the size of Stack:";
    cin>>size;
    Stack s(size);
    s.isEmpty();
    s.isFull();
    s.push(5);
    s.isEmpty();
    s.peek();
    s.pop();


    

    return 0;
}
