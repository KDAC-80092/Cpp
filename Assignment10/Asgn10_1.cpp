#include <iostream>
using namespace std;
#define SIZE 5

template <class T>
class Stack
{
    int size;
    int top;
    T *arr;

public:
    Stack(int size)
    {
        this->top = -1;
        if (size > 0)
        {
            this->size = size;
            this->arr = new T[size];
        }
        else
        {
            this->size = SIZE;
            this->arr = new T[SIZE];
        }
    }

    void push(T a)
    {
        if (this->top == this->size - 1)
        {
            cout << "Stack is Full!" << endl;
        }
        else
        {
            this->top++;
            this->arr[top] = a;
            cout << "Element Added Successfully!" << endl;
        }
    }

    void pop()
    {
        if (this->top == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            this->arr[top];
            this->top--;
            cout << "Element Removed Successfully!" << endl;
        }
    }

    void peek()
    {
        if (this->top == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Element is:" << this->arr[top] << endl;
        }
    }

    void isEmpty()
    {
        if (this->top == -1)
        {
            cout << "Stack Is Empty." << endl;
        }
        else
        {
            cout << "Space available in Stack." << endl;
        }
    }

    void isFull()
    {
        if (this->top == size - 1)
        {
            cout << "Stack is Full." << endl;
        }
        else
        {
            cout << "Stack is  not Full." << endl;
        }
    }
};

class Box
{
    int length;
    int breadth;
    int height;

public:
    Box()
    {
        this->length = 1;
        this->breadth = 2;
        this->height = 3;
    }
    Box(int l, int b, int h)
    {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
    void display()
    {
        cout << "Length = " << length << "Breadth = " << breadth << "Height = " << height << endl;
    }

    friend std::ostream &operator<<(ostream &os, Box &box)
    {
        os << box.length << box.breadth << box.height;
        return os;
    }
};

int main()
{
    // int size;
    // cout<<"Enter size of stack:";
    // cin>>size;
    // Stack<int> s(5);
    // s.push(10);
    // s.push(20);
    // s.peek();
    // s.isEmpty();
    // s.isFull();
    // s.pop();
    // s.peek();
    // cout << "*************************************************";
    // Stack<double> s1(5);
    // s1.push(10.00);
    // s1.push(20.20);
    // s1.peek();
    // s1.isEmpty();
    // s1.isFull();
    // s1.pop();
    // s1.peek();

    Stack<Box> boxStack(5);
    Box box1(10, 20, 30);
    Box box2(5, 6, 7);

    boxStack.push(box1);
    boxStack.push(box2);

    cout << "***************************" << endl;
    boxStack.peek();

    cout << "****************************" << endl;
    boxStack.pop();

    cout << "****************************" << endl;

    boxStack.peek();
    return 0;
}
