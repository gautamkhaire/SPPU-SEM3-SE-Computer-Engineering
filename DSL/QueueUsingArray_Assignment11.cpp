#include<iostream>
#define Max 20
using namespace std;

class QueueUsingArray
{
    int front;
    int rear;
    int arr[Max];

    public:
    QueueUsingArray()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        if(front==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if(front==(Max-1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int element)
    {
        if(isFull())
        {
            cout<<"Queue is Full.\n";
        }
        else
        {
            if(front==-1)
            {
                arr[0]=element;
                front=0;
                rear=1;
            }
            else
            {
                arr[rear]=element;
                ++rear;
            }
            
        }
    }

    void remove()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty.\n";
        }
        else
        {
            arr[front]=-1;
            ++front;
        }
    }

    void display()
    {
        int temp=front;
        while(temp!=(rear))
        {
            cout<<arr[temp]<<" ";
            ++temp;
        }
        cout<<endl;
    }

};

int main()
{
    QueueUsingArray qobj;
    cout<<"--------Menu--------"<<endl;
    cout<<"1. Insert Element in Queue"<<endl;
    cout<<"2. Remove Element from Queue"<<endl;
    cout<<"3. Display the Queue"<<endl;
    cout<<"4. IsEmpty "<<endl;
    cout<<"5. IsFull"<<endl;
    while(1)
    {
        int option;
        cout<<"Enter the option : "<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            int element;
            cout<<"Enter the element you want to insert in queue : ";
            cin>>element;
            qobj.insert(element);
            break;
        case 2:
            qobj.remove();
            break;
        case 3:
            qobj.display(); 
            break;
        case 4:
            cout<<boolalpha<<qobj.isEmpty();
            break;
        case 5:
            cout<<boolalpha<<qobj.isFull();  
            break;         
        }
        cout<<endl;
        char c;
        cout<<"Do you want to continue(y/n) ?"<<endl;
        cin>>c;
        if(c=='y')
        {
            continue;
        }
        else if(c=='n')
        {
            break;
        }
    }



    return 0;
}