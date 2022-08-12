#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class StackUsingLinkedList
{
    Node* head;
    int size;

    public:
    StackUsingLinkedList()
    {
        head=NULL;
        size=0;
    }

    bool isEmpty()
    {
        return size==0;
    }

    void push(int element)
    {
        Node* newNode=new Node(element);
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }
        size++;
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty !"<<endl;
            return ;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
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
        Node* temp=head;
        int temp_data=temp->data;
        head=head->next;
        delete temp;
        size--;
        return temp_data;
    }

    int Top()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty !"<<endl;
            return INT_MIN;
        }
        return head->data;
    }
};
int main()
{
    StackUsingLinkedList obj;
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
                cout <<obj.isEmpty();
                cout<<endl;
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