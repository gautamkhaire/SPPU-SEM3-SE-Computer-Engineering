#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    int priority;
    Node *next;

public:
    Node()
    {
        data = 0;
        priority = 0;
        next = NULL;
    }
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        next = NULL;
    }
    friend class PriorityQueue;
};
class PriorityQueue
{
private:
    Node *head;

public:
    PriorityQueue()
    {
        head = NULL;
    }

    void enqueue(int data, int priority)
    {
        Node *temp = new Node(data, priority);
        if (head == NULL || priority < head->priority)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            Node *temp1 = head;
            while (temp1->next != NULL && temp1->next->priority <= priority)
            {
                temp1 = temp1->next;
                temp->next = temp1->next;
                temp1->next = temp;
            }
        }
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            cout << "Deleted item is : " << temp->data << endl;
            head = head->next;
            delete temp;
        }
    }

    void display()
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        else
        {
            cout << "Queue is :" << endl;
            while (temp != NULL)
            {
                cout << temp->priority << " " << temp->data << endl;
                temp = temp->next;
            }
        }
    }
};
int main()
{
    PriorityQueue obj;
    int option, data, priority;
    do
    {
        cout << "------Menu------" << endl;
        cout << " 1. enqueue" << endl;
        cout << " 2. dequeue" << endl;
        cout << " 3. Display" << endl;
        cout << " 4. Exit" << endl;
        cout << "Enter the option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the data : " << endl;
            cin >> data;
            cout << "Enter the " << data << " priority : " << endl;
            cin >> priority;
            obj.enqueue(data, priority);
            break;
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            break;
        default:
            cout << "Wrong option";
            break;
        }
    } while (option != 4);

    return 0;
}