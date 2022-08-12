#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int element)
    {
        data = element;
        next = NULL;
    }
    friend class QueueUsingLinkedList;
};
class QueueUsingLinkedList
{
    Node *front;
    Node *rear;

public:
    QueueUsingLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    void insert(int element)
    {
        Node *newNode = new Node(element);
        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void remove()
    {
        if (isEmpty())
        {
            cout << "The queue is empty ." << endl;
            return;
        }
        else
        {
            if (front->next == NULL)
            {
                delete front;
                front == NULL;
                rear = NULL;
            }
            else
            {
                Node *temp_address = front->next;
                front->next = NULL;
                delete front;
                front = temp_address;
            }
        }
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "The queue is empty ." << endl;
            return;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    QueueUsingLinkedList qobj;
    cout << "--------Menu--------" << endl;
    cout << "1. Insert Element in Queue" << endl;
    cout << "2. Remove Element from Queue" << endl;
    cout << "3. Display the Queue" << endl;
    cout << "4. IsEmpty " << endl;
    while (1)
    {
        int option;
        cout << "Enter the option : " << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            int element;
            cout << "Enter the element you want to insert in queue : ";
            cin >> element;
            qobj.insert(element);
            break;
        case 2:
            qobj.remove();
            break;
        case 3:
            qobj.display();
            break;
        case 4:
            cout << boolalpha << qobj.isEmpty();
            break;
        }
        cout << endl;
        char c;
        cout << "Do you want to continue(y/n) ?" << endl;
        cin >> c;
        if (c == 'y')
        {
            continue;
        }
        else if (c == 'n')
        {
            break;
        }
    }
    return 0;
}