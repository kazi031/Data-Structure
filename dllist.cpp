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
    Node *head;
    Node *tail;
public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int v)
    {
        Node *temp=new Node;
        temp->prev=NULL;
        temp->next=NULL;
        temp->val=v;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            temp->next=head;
            head->prev=temp;
            head=temp;
        }

    }
    void push_back(int v)
    {
        Node* temp=new Node;
        temp->prev=NULL;
        temp->next=NULL;
        temp->val=v;
        if(tail==NULL)
        {
            push_front(v);
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
    void push_before_a_given_node(int s,int v)
    {
        if(head->val==s)
        {
            push_front(v);
        }
        else{
        Node* temp2=new Node;
        temp2->prev=NULL;
        temp2->val=v;
        temp2->next=NULL;
        Node* temp=head;
        while(temp->val!=s)
        {
            temp=temp->next;
        }
        temp2->next=temp;
        temp2->prev=temp->prev;
        temp->prev->next=temp2;
        temp->prev=temp2;}
    }
    void push_after_a_given_node(int s,int v)
    {
        if(tail->val==s)
        {
            push_back(v);
        }
        else
        {
            Node* temp2=new Node;
            temp2->prev=NULL;
            temp2->next=NULL;
            temp2->val=v;
            Node* temp=head;
            while(temp->val!=s)
            {
                temp=temp->next;
            }
            temp2->next=temp->next;
            temp2->prev=temp;
            temp->next->prev=temp2;
            temp->next=temp2;
        }
    }
    int pop_front()
    {
        if(head==NULL)
        {
            cout<<"The LinkedList is empty"<<endl;
            return -1;
        }
        else if(head==tail)
        {
            Node* temp=head;
            head=NULL;
            tail=NULL;
            int ret=temp->val;
            delete temp;
            return ret;
        }
        else
        {
            Node* temp=head;
            head=head->next;
            head->prev=NULL;
            int ret=temp->val;
            delete temp;
            return ret;
        }
    }
    int pop_back()
    {
        if(tail==NULL)
        {
            cout<<"The LinkedList is empty!";
            return -1;
        }
        else if(head==tail)
        {
            return pop_front();
        }
        else
        {
            Node* temp=tail;
            tail=tail->prev;
            int ret=temp->val;
            tail->next=NULL;
            delete temp;
            return ret;
        }
    }
    void display()
    {
        Node* temp=head;
        if(head==NULL)
        {
            cout<<"The LinkedList is empty."<<endl;
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
        Node* temp=tail;
        if(tail==NULL)
        {
            cout<<"The LinkedList is empty."<<endl;
        }
        else{
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->prev;
        }
        cout<<endl;}
    }
    void dispose()
    {
        Node* temp;
        while(head!=NULL)
        {
            temp=head;
            //cout<<temp->val<<" ";
            head=head->next;
            delete temp;
        }
    }
    ~DoubleLinkedList()
    {
        dispose();
        cout<<"All elements are cleared!"<<endl;
    }
};
int main()
{
    DoubleLinkedList list1,list2;
    /*list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);
    list1.push_front(40);
    list1.push_front(50);
    list1.display();
    list1.reverse_display();*/
    list2.push_back(10);
    list2.push_back(20);
    list2.push_back(30);
    list2.push_back(40);
    list2.push_back(50);
    list2.display();
    list2.reverse_display();
    cout<<list2.pop_front()<<" Has been popped!"<<endl;
    list2.display();
    list2.reverse_display();
    /*cout<<list1.pop_back()<<" Has been popped!"<<endl;
    list1.display();
    list1.reverse_display();*/
    list2.push_before_a_given_node(30,25);
    list2.display();
    list2.reverse_display();
    list2.push_after_a_given_node(30,35);
    list2.display();
    list2.reverse_display();
}
