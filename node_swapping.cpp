#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
};
class LinkedList
{
    Node* head;
public:
    LinkedList()
    {
        head=NULL;
    }
    void push_front(int v)
    {
        Node* temp=new Node;
        temp->val=v;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    void display()
    {
        Node * temp = head;
        cout<<"Resultant array:"<<endl;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    int pop_front()
    {
        Node *temp;
        temp=head;
        head=head->next;
        int ret=temp->val;
        delete temp;
        return  ret;
    }
    void reverse()
    {
        Node* a = NULL;
        Node* c;
        while(c!=NULL)
        {
            Node* b = head;
            c = head->next;
            c->next=b;
            b->next=a;
            head=head->next;
        }
    }
    void dispose()
    {
        Node* temp=head;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            int ret=temp->val;
            cout<<ret<<" ";
            delete temp;
        }
    }
    ~LinkedList()
    {
        cout<<"clearing all elements....."<<endl;
        dispose();
    }
};
int main()
{
    LinkedList list1;
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);
    list1.push_front(40);
    list1.display();
    cout<<list1.pop_front()<<" is popped"<<endl;
    list1.reverse();
    list1.display();
}
