#include<iostream>
#include<string.h>
using namespace std;
class Node
{
public:
    char data;
    Node *next;

    Node(char data)
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

    void push(char element)
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

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty !"<<endl;
            return ;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        size--;
    }

    char Top()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty !"<<endl;
            return '0';
        }
        return head->data;
    }
};

bool wellParenthesized(string s)
{
    StackUsingLinkedList st;
    int len=s.length();
    char ch;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            st.push(s[i]);
            continue;
        }

        if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(st.isEmpty())
            {
                return false;
            }
            else
            {
                switch (s[i])
                {
                case ')':
                    ch=st.Top();
                    st.pop();
                    if(ch=='{' || ch=='[')
                    {
                        return false;
                    }
                    break;
                case '}':
                    ch=st.Top();
                    st.pop();
                    if(ch=='(' || ch=='[')
                    {
                        return false;
                    }
                    break;
                case ']':
                    ch=st.Top();
                    st.pop();
                    if(ch=='(' || ch=='{')
                    {
                        return false;
                    }
                    break;
                
                default:
                    break;
                }
            }
        }
    }
    if(st.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string s;
    cout<<"Enter the expression : "<<endl;
    cin>>s;
    bool ans=wellParenthesized(s);
    if(ans)
    {
        cout<<s<<" this expression is well parenthesized !! "<<endl;
    }
    else
    {
        cout<<s<<" this expression is not well parenthesized ."<<endl;
    }

    return 0;
}