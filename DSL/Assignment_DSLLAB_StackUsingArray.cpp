#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class StackUsingArray
{
    vector<int> data;
    int top;

public:
    StackUsingArray()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return data.size() == 0;
    }

    void push(int element)
    {
        
        data.push_back(element);
        top++;
        
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty !" << endl;
        }
        else
        {
            int i=top;
            cout << "Elements in Stack are : ";
            while(i>=0)
            {
                cout<<data[i]<<" ";
                i--;
            }
            cout<<endl;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !" << endl;
            return INT_MIN;
                
        }
        else
        {
            int temp=data[top];
            data.pop_back();
            top--;
            return temp;
        }
    }

    int Top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty !" << endl;
            return INT_MIN;
        }
        else
        {
            return data[top];
        }
    }
};
int main()
{
    StackUsingArray obj;
    cout << "-------Menu-------" << endl;
    cout << "1.isEmpty()\n2.push()\n3.display()\n4.pop()\n5.top()\n";
    int option;
    cout<<"Enter the option : "<<endl;
    cin >> option;
    while(true)
    {
        switch (option)
        {
            case 1:
                cout << obj.isEmpty();
                break;
            case 2:
                int element;
                cout << "Enter the element you want to push in stack" << endl;
                cin >> element;
                obj.push(element);
                break;
            case 3:
                obj.display();
                break;
            case 4:
                cout<<"The element pop is : "<<obj.pop()<<endl;
                break;
            case 5:
                cout<<"The element at top of stack is : "<<obj.Top()<<endl;
                break;

            default:
                break;
        }
        cout<<"Enter the option : "<<endl;
        cin >> option;
        if(!(option>=1 && option<=5))
        {
            break;
        }
        
    }

    return 0;
}

#include<iostream>
#include<climits>
using namespace std;
#define MAX 20
class StackUsingArray
{
    private:
    int data[MAX];
    int top;
    public:
    StackUsingArray()
    {
        top=-1;
    }

    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if(top==MAX-1)
        {
            return true;
        }
        return false;
    }

    void push(int element)
    {
        if(isFull())
        {
            cout<<"Stack is Full !"<<endl;
            return ;
        }
        data[++top]=element;
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty !"<<endl;
            return ;
        }
        int i=top;
        while(i>=0)
        {
            cout<<data[i]<<" ";
            i--;
        }
        cout<<endl;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty !"<<endl;
            return INT_MIN;
        }
        int i=top;
        top--;
        return data[i];
    }

    int Top()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty !"<<endl;
            return INT_MIN;
        }
        return data[top];
    }
};
int main()
{
    StackUsingArray obj;
    cout << "-------Menu-------" << endl;
    cout << "1.isEmpty()\n2.isFull()\n3.push()\n4.display()\n5.pop()\n6.top()\n";
    int option;
    cout<<"Enter the option : "<<endl;
    cin >> option;
    while(true)
    {
        switch (option)
        {
            case 1:
                cout <<obj.isEmpty();
                cout<<endl;
                break;
            case 2:
                cout <<obj.isFull();
                cout<<endl;
                break;
            case 3:
                int element;
                cout << "Enter the element you want to push in stack" << endl;
                cin >> element;
                obj.push(element);
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout<<"The element pop is : "<<obj.pop()<<endl;
                break;
            case 6:
                cout<<"The element at top of stack is : "<<obj.Top()<<endl;
                break;

            default:
                break;
        }
        cout<<"Enter the option : "<<endl;
        cin >> option;
        if(!(option>=1 && option<=6))
        {
            break;
        }
        
    }
    return 0;
}