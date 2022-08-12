#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *prev;
    Node *next;

public:
    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    friend class Deque;
};
class Deque
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Deque()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueueF(int data)
    {
        Node *newNode = new Node(data);

        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        size++;
    }

    void enqueueR(int data)
    {
        Node *newNode = new Node(data);

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeueF()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            else
            {
                front->prev = NULL;
            }
            delete temp;
        }
        size--;
    }

    void dequeueR()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = rear;
            rear = rear->prev;
            if (rear == NULL)
            {
                front = NULL;
            }
            else
            {
                rear->next = NULL;
            }
            delete temp;
        }
        size--;
    }

    void display()
    {
        Node *temp = front;
        cout << "Deque is :" << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
};
int main()
{
    Deque obj;
    int option,data;
    do
    {
        cout << "------Menu------" << endl;
        cout << " 1. enqueueF" << endl;
        cout << " 2. enqueueR" << endl;
        cout << " 3. dequeueF" << endl;
        cout << " 4. dequeueR" << endl;
        cout << " 5. isEmpty" << endl;
        cout << " 6. Display" << endl;
        cout << " 7. Exit" << endl;
        cout << "Enter the option : ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter the data : " << endl;
            cin >> data;
            obj.enqueueF(data);
            break;
        case 2:
            cout << "Enter the data : " << endl;
            cin >> data;
            obj.enqueueR(data);
            break;
        case 3:
            obj.dequeueF();
            break;
        case 4:
            obj.dequeueR();
            break;
        case 5:
            cout << obj.isEmpty() << endl;
            break;
        case 6:
            obj.display();
            break;
        case 7:
            break;
        default:
            cout << "Wrong option" << endl;
            break;
        }

    } while (option != 7);
    return 0;
}