#include <iostream>
using namespace std;

class Node
{
    int startTime;
    int endTime;
    int minDuration;
    int maxDuration;
    int flag;
    Node *next;

public:
    
    Node()
    {
        startTime = 0;
        endTime = 0;
        minDuration = 0;
        maxDuration = 0;
        flag = 0;
        next = NULL;
    }
    friend class ScheduleDay;
};

class ScheduleDay
{
    Node *head;
public:
    ScheduleDay()
    {
        head=NULL;
    }

    void create()
    {
        Node *newNode=new Node();
        cout<<"\n Enter Start Time (format HH:MM): ";
        cin>>newNode->startTime;
        cout<<"\n Enter End Time (format HH:MM): ";
        cin>>newNode->endTime;
        cout<<"\n Enter Minimum Duration in mins: ";
        cin>>newNode->minDuration;
        cout<<"\n Enter Maximum Duration in mins: ";
        cin>>newNode->maxDuration;
        newNode->flag=1;
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    
    void display()
    {
        int count=1;
        Node *temp=head;
        cout<<"\n ----Appointment Schedule----";
        while(temp!=NULL)
        {
            cout<<"\n"<<count;
            cout<<"\n Start Time (format HH:MM): "<<temp->startTime;
            cout<<"\n End Time (format HH:MM): "<<temp->endTime;
            cout<<"\n Minimum Duration in mins: "<<temp->minDuration;
            cout<<"\n Maximum Duration in mins: "<<temp->maxDuration;
            if(temp->flag==1)
            {
                cout<<"\n Booked !!";
            }
            else
            {
                cout<<"\n Free Slot ";
            }
            count++;
            temp=temp->next;
        }

    }

    void booked()
    {
        int start;
        Node *temp=head;

        cout<<"\nPlease enter Appointment time : ";
        cin>>start;

        while(temp!=NULL)
        {
            if(start==temp->startTime)
            {
                if(temp->flag==1)
                {
                    cout<<"\n Appointment Slot is Booked !!";
                }
                else
                {
                    cout<<"\n Appointment Slot is Available ";
                    char ch;
                    cout<<"\n Do you want to book a appointment now ? (y/n) ";
                    cin>>ch;
                    if(ch=='y')
                    {
                        create();
                    }
                }
            }
            temp=temp->next;
        }

    }

    void cancel()
    {
        int start;
        Node *temp=head;

        cout<<"\nPlease enter Appointment time to cancel : ";
        cin>>start;

        while(temp!=NULL)
        {
            if(start==temp->startTime)
            {
                if(temp->flag==1)
                {
                    cout<<"\n Your Appointment Slot is Cancelled !!";
                    temp->flag=0;
                }
                else
                {
                    cout<<"\n Your Appointment was not Booked ";
                }
            }
            temp=temp->next;
        }
    }

    void sortTime()
    {
        Node *temp1=head;
        Node *temp=head;
        int temp_val=0;
        while(temp1!=NULL)
        {
            while(temp->next!=NULL)
            {
                if(temp->startTime > temp->next->startTime)
                {
                    temp_val=temp->startTime;
                    temp->startTime=temp->next->startTime;
                    temp->next->startTime=temp_val;

                    temp_val=temp->endTime;
                    temp->endTime=temp->next->endTime;
                    temp->next->endTime=temp_val;

                    temp_val=temp->minDuration;
                    temp->minDuration=temp->next->minDuration;
                    temp->next->minDuration=temp_val;

                    temp_val=temp->maxDuration;
                    temp->maxDuration=temp->next->maxDuration;
                    temp->next->maxDuration=temp_val;
                    
                }
            }
            temp1=temp1->next;
        }
    }

    void sortPointer()
    {
        Node *current=head;
        Node *temp=head->next;
        Node *previous=NULL;
        while(current!=NULL)
        {
            while(temp!=NULL)
            {
                if(current->startTime > temp->startTime)
                {
                    previous=current->next;
                    current->next=temp->next;
                    temp->next=current;

                }
                temp=temp->next;
            }
            current=current->next;
            temp=current->next;
        }

    }


};
int main()
{
    ScheduleDay obj;
    int option;
    char c;
    cout<<"\n----Menu----";
    cout<<"\n 1. Create Appointment ";
    cout<<"\n 2. Display Free Slot";
    cout<<"\n 3. Book an Appointment";
    cout<<"\n 4. Cancel an Appointment";
    cout<<"\n 5. Sort Slots based on Time";
    cout<<"\n 6. Sort Slots using Pointer Manipulation";
    cout<<endl;
    do
    {
        cout<<"Enter the option :"<<endl;
        cin>>option;
        switch (option)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.booked();
            break;
        case 4:
            obj.cancel();
            break;
        case 5:
            obj.sortTime();
            break;

        case 6:
            obj.sortPointer();
            break;   
        
        default:
            cout<<"\nWrong Choice !";
            break;
        }
        cout<<"\nDo you want to continue ? (y/n)";
        cin>>c;

    }while(c=='y');
    
}

