#include<cstdio>
#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* prev;
    Node* next;
};
class DoubleLinkedList
{
    Node* head;
    Node* tail;
public:
    DoubleLinkedList()
    {
        head=NULL;
        tail=NULL;
    }
    void push_front(int v)
    {
        Node* temp=new Node;
        temp->prev=NULL;
        temp->next=NULL;
        temp->val=v;
        if(head==NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }
    void display()
    {
        Node* temp;
        temp=head;
        if(head==NULL)
        {
            cout<<"The linkedlist is empty"<<endl;
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    void reverse_display()
    {
        Node* temp;
        temp=tail;
        if(head==NULL)
        {
            cout<<"The linkedlist is empty"<<endl;
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->val<<" ";
                temp=temp->prev;
            }
            cout<<endl;
        }
    }
    int pop_front()
    {
        Node* temp;
        if(head==NULL)
        {
            cout<<"The linklist is empty"<<endl;
            return -1;
        }
        else if(head==tail)
        {
            int t=head->val;
            delete head;
            head=NULL;
            tail=NULL;
            return t;
        }
        else
        {
            temp=head;
            temp->next->prev=NULL;
            head=head->next;
            int t=temp->val;
            delete temp;
            return t;
        }
    }
    dispose()
    {
        Node* temp=NULL;
        while(head!=NULL)
        {
            temp=head;
            cout<<endl<<temp->val<<endl;
            head=head->next;
            delete temp;
        }
    }
    ~DoubleLinkedList()
    {
        dispose();
        cout<<endl<<"destructing.....";
    }
};
int main()
{
    DoubleLinkedList list1;
    list1.push_front(10);
    /*list1.push_front(20);
    list1.push_front(30);
    list1.push_front(40);
    list1.push_front(50);*/
    list1.display();
    list1.reverse_display();
    cout<<list1.pop_front()<<" is popped"<<endl;
    list1.display();
    list1.reverse_display();
}
