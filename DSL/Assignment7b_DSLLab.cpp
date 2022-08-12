#include<iostream>
using namespace std;
class binaryNumber;
class Node
{
    private:
    Node *previous;
    Node *next;
    bool data;
    public:
    Node()
    {
        previous=NULL;
        next=NULL;
    }
    Node(bool data)
    {
        this->data=data;
        previous=next=NULL;
    }
    friend class binaryNumber;
};
class binaryNumber
{
    Node *last;
    public:
    binaryNumber()
    {
        last=NULL;
    }
    void DectoBinary(int num)
    {
        bool rem;
        Node *temp;
        rem=num%2;
        last=new Node(rem);
        num=num/2;
        while(num !=0)
        {
            rem=num%2;
            num=num/2;
            temp=new Node(rem);
            temp->next=last;
            last->previous=temp;
            last=temp;
        }
    }
    // bineryNumber complement()
    // {
    //     binaryNumber obj3;
    //     Node *temp=this->last;
    //     Node *temp_complement;
    //     temp_complement=obj3.last;
    //     while(temp!=NULL)
    //     {
    //         if(temp->data==1)
    //         {
    //             temp_complement=new Node(0);
    //         }
    //         else if(temp->data==0)
    //         {
    //             temp_complement=new Node(1);
    //         }
    //         temp=temp->next;
    //         if(temp_complement!=NULL)
    //         {
    //             temp_complement->next=obj3.last;
    //             obj3.last->previous=temp_complement;
    //             obj3.last=temp_complement;
    //         }
    //     }
    //     return obj3;
    // }
    void Display()
    {
        Node *temp;
        temp=last;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
        }
    }
    bool add(bool n)
    {
        Node *temp=new Node(n);
        if(last==NULL)
        {
            last=temp;
        }
        else
        {
            temp->next=last;
            last->previous=temp;
            last=temp;
        }
        return 1;
    }
};
// binaryNumber binaryNumber::operator+(binaryNumber num2)
// {
//     binaryNumber sum;
//     Node *a=this->last;
//     Node *b=num2.last;
//     bool carry=0;
//     while(a->next!=NULL)
//     {
//         a=a->next;
//     }
//     while(b->next!=NULL)
//     {
//         b=b->next;
//     }
//     while(a!=NULL && b!=NULL)
//     {
//         sum.add=(a->data^b->data^carry);
//         carry=(a->data && b->data)||(a->data && carry) || (b->data && carry)
//         a=a->previous;
//         b=b->previous;
//     }
//     while(a!=NULL)
//     {
//         sum.add(a->data^carry);
//         a=a->previous;
//     }
//     while(b!=NULL)
//     {
//         sum.add(b->data^carry);
//         b=b->previous;
//     }
//     sum.add(carry);
//     return sum;


// }
int main()
{
    int num1,num2;
    cin>>num1>>num2;
    // int choice;
    // cin>>choice;
    binaryNumber obj1,obj2,obj3;
    obj1.DectoBinary();
    obj2.DectoBinary();
    obj1.Display();
    cout<<" + ";
    obj2.Display();
    cout<<" = ";
    obj3=obj1+obj2;
    obj3.Display();
    // obj.DectoBinary(num);
    // cout<<"Binary representation of "<<num<<" is :"<<endl;
    // obj.Display();
    // cout<<endl;
    // obj.complement();
    // cout<<"1's complement of "<<num<<" is :"<<endl;
    // obj.Display();
    return 0;
}