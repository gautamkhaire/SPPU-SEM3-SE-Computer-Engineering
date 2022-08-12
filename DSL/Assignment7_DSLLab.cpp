// #include <iostream>
// using namespace std;
// class CineMax;
// class Node
// {
// private:
//     bool ticketStatus;
//     Node *next;

// public:
//     Node()
//     {
//         ticketStatus = false;
//         next = NULL;
//     }
//     friend class CineMax;
// };
// class CineMax
// {
//     Node *head[10];

// public:
//     CineMax()
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             head[i] = NULL;
//         }
//     }
//     void PrepareTheater()
//     {
//         for (int i = 0; i < 10; i++)
//         {
//             for (int j = 0; j < 7; j++)
//             {
//                 if (head[i] == NULL)
//                 {
//                     head[i] = new Node;
//                 }
//                 else
//                 {
//                     Node *temp;
//                     temp = head[i];
//                     while (temp->next != NULL)
//                     {
//                         temp = temp->next;
//                     }
//                     Node *newNode= new Node;
//                     temp->next=newNode;
//                 }
//             }
//         }
//     }
//     void BookSeat()
//     {
//         int row,seat;
//         cout<<"Enter the row number : "<<endl;
//         cin>>row;
//         cout<<"Enter the seat number of "<<row<<" row "<<endl;
//         cin>>seat;
//         if(row<=9 && seat<=6)
//         {
//             Node *temp=head[row];
//             for(int i=0;i<seat;i++)
//             {
//                 temp=temp->next;
//             }
//             if(temp->ticketStatus==false)
//             {
//                 temp->ticketStatus=true;
//                 cout<<"Seat Booked Successful !!"<<endl;
//             }
//             else
//             {
//                 cout<<"Sorry, Seat is booked !!"<<endl;
//                 char repeat;
//                 cout<<"Do you want to try booking the seat again :"<<endl;
//                 if(repeat=='y')
//                 {
//                     BookSeat();
//                 }

//             }
//         }
//         else
//         {
//             cout<<"Invalid Choice "<<endl;
//             BookSeat();
//         }
//         DisplayTheater();
//     }
//     void CancelSeat()
//     {
//         int row,seat;
//         cout<<"Enter the row number : "<<endl;
//         cin>>row;
//         cout<<"Enter the seat number of "<<row<<" row "<<endl;
//         cin>>seat;
//         if(row<=9 && seat<=6)
//         {
//             Node *temp=head[row];
//             for(int i=0;i<seat;i++)
//             {
//                 temp=temp->next;
//             }
//             if(temp->ticketStatus==true)
//             {
//                 temp->ticketStatus=false;
//                 cout<<"Booking Cancelled !!"<<endl;

//             }
//             else
//             {
//                 cout<<"Sorry , seat was not booked"<<endl;
//             }
//         }
//         else
//         {
//             cout<<"Invalid Choice"<<endl;
//         }
//         DisplayTheater();
//     }
//     void DisplayTheater()
//     {
//         for(int i=0;i<10;i++)
//         {
//             Node *temp=head[i];
//             for(int j=0;j<7;j++)
//             {
//                 cout<<temp->ticketStatus<<" ";
//                 temp=temp->next;
//             }
//             cout<<endl;
//         }
//     }
    
// };

// int main()
// {
//     CineMax obj;
//     obj.PrepareTheater();
//     cout<<"\n 1. Book a seat \n 2. Cancel a booked seat \n 3. Display Theater"<<endl;
//     int choice;
//     cin>>choice;
    
//     switch (choice)
//     {
//     case 1:
//         obj.BookSeat();
//         break;
//     case 2:
//         obj.CancelSeat();
//         break;
//     case 3:
//         obj.DisplayTheater();
//         break;    
    
//     default:
//         cout<<"Invalid choice";
//         break;
//     }
//     cout<<endl;
//     return 0;
// }
#include <iostream>
using namespace std;
class CineMax;
class Node
{
private:
    bool ticketStatus;
    Node *previous,*next;

public:
    Node()
    {
        ticketStatus = false;
    }
    friend class CineMax;
};
class CineMax
{
    Node *head[10],*tail[10];

public:
    CineMax()
    {
        for (int i = 0; i < 10; i++)
        {
            head[i] =tail[i]= NULL;
        }
    }
    void PrepareTheater()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                Node *temp=new Node;
                if (head[i] == NULL)
                {
                    head[i] = temp;
                    tail[i] = temp;
                    head[i]->next=head[i];
                    head[i]->previous=head[i];
                    tail[i]->next=head[i];
                    tail[i]->previous=head[i];
                }
                else
                {
                    Node *temp1;
                    temp1 = head[i];
                    while (temp1->next != head[i])
                    {
                        temp1 = temp1->next;
                    }
                    temp1->next=temp;
                    temp->previous=temp1;
                    temp->next=head[i];
                    temp=tail[i];
                    head[i]->previous=tail[i];
                }
            }
        }
    }
    void BookSeat()
    {
        int row,seat;
        cout<<"Enter the row number : "<<endl;
        cin>>row;
        cout<<"Enter the seat number of "<<row<<" row "<<endl;
        cin>>seat;
        if(row<=9 && seat<=6)
        {
            Node *temp=head[row];
            for(int i=0;i<seat;i++)
            {
                temp=temp->next;
            }
            if(temp->ticketStatus==false)
            {
                temp->ticketStatus=true;
                cout<<"Seat Booked Successful !!"<<endl;
            }
            else
            {
                cout<<"Sorry, Seat is booked !!"<<endl;
                char repeat;
                cout<<"Do you want to try booking the seat again :"<<endl;
                if(repeat=='y')
                {
                    BookSeat();
                }

            }
        }
        else
        {
            cout<<"Invalid Choice "<<endl;
            BookSeat();
        }
        DisplayTheater();
    }
    void CancelSeat()
    {
        int row,seat;
        cout<<"Enter the row number : "<<endl;
        cin>>row;
        cout<<"Enter the seat number of "<<row<<" row "<<endl;
        cin>>seat;
        if(row<=9 && seat<=6)
        {
            Node *temp=head[row];
            for(int i=0;i<seat;i++)
            {
                temp=temp->next;
            }
            if(temp->ticketStatus==true)
            {
                temp->ticketStatus=false;
                cout<<"Booking Cancelled !!"<<endl;

            }
            else
            {
                cout<<"Sorry , seat was not booked"<<endl;
            }
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
        }
        DisplayTheater();
    }
    void DisplayTheater()
    {
        for(int i=0;i<10;i++)
        {
            Node *temp=head[i];
            for(int j=0;j<7;j++)
            {
                cout<<temp->ticketStatus<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    CineMax obj;
    obj.PrepareTheater();
    cout<<"\n 1. Book a seat \n 2. Cancel a booked seat \n 3. Display Theater"<<endl;
    int choice;
    cin>>choice;
    
    switch (choice)
    {
    case 1:
        obj.BookSeat();
        break;
    case 2:
        obj.CancelSeat();
        break;
    case 3:
        obj.DisplayTheater();
        break;    
    
    default:
        cout<<"Invalid choice";
        break;
    }
    cout<<endl;
    return 0;
}
