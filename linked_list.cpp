#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node *next;
};
struct Linkedlist
{
    Node *head=NULL;
public:
    void push_front(int v)
    {
        Node *temp=new Node;
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
    int pop_front()
    {
        Node* temp;
        temp=head;
        head=head->next;
        int ret=temp->val;
        delete temp;
        return ret;
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"No Element";
        }
        else
        {
            Node *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    void push_back(int v)
    {
        if(head==NULL)
        {
            push_front(v);
        }
        else
        {
            Node* temp=new Node;
            temp->val=v;
            temp->next=NULL;
            Node* temp2;
            temp2=head;
            while(temp2->next!=NULL)
            {
                temp2=temp2->next;
            }
            temp2->next=temp;
        }
    }
    void delete_by_node(Node* node)
    {
        //cout<<"~###";
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            return;
        }
       /* else if(head->next==node)
        {
            pop_front();
        }*/
        if(head==node)
        {
            pop_front();
        }
        else
        {
            Node* temp=head;
            while(temp->next!=node)
            {
                //cout<<"~###";
                temp=temp->next;
            }
            Node* temp2=temp->next;
            temp->next=temp->next->next;
            delete temp2;
        }
    }
    Node* get_node(int n)
    {
        Node* temp=head;
        for(int i=1;i<n;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
    void delete_duplicate()
    {
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            return;
        }
        else
        {
            Node* temp=head;
            while(temp->next!=NULL)
            {
                Node* temp2=temp->next;
                while(temp2!=NULL)
                {
                    if(temp2->val==temp->val)
                    {
                        Node* temp3;
                        temp3=temp2;
                        temp2=temp2->next;
                    // delete temp3;
                        delete_by_node(temp3);
                        if(temp->next==NULL)
                        {
                            return;
                        }
                    }
                    else
                    {
                        temp2=temp2->next;
                    }
                }
                temp=temp->next;
            }
        }
    }
    void reverse()
    {
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            return;
        }
        else{
        Node* a=NULL;
        Node* b=head;
        Node* c=head->next;
        while(c!=NULL)
        {
           b->next=a;
           a=b;
           b=c;
           c=c->next;
        }
        b->next=a;
        head=b;
        }

    }
    int get_size(Node* node)
    {
        Node* temp=node;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        return c;
    }
    void push_after_node(Node* node,int v)
    {
        if(head==node)
        {
            push_back(v);
        }
        else
        {
            Node* temp=new Node;
            temp->next=NULL;
            temp->val=v;
            temp->next=node->next;
            node->next=temp;

        }

    }
    void push_before_node(Node* node,int v)
    {
        if(head==node)
        {
            push_front(v);
        }
        else
        {
            Node* temp=new Node;
            temp->next=NULL;
            temp->val=v;
            Node* temp2=head;
            while(temp2->next!=node)
            {
                temp2=temp2->next;
            }
            temp->next=node;
            temp2->next=temp;
        }
    }
    void merge(Linkedlist l2)
    {
        Node* temp1=head;
        Node* temp2=l2.get_head();
        //cout<<temp2->val<<endl;
        while(temp1!=NULL)
        {
            Node* temp3=temp1;
            temp1=temp1->next;
            push_before_node(temp3,temp2->val);
            temp2=temp2->next;
        }
    }
    void dispose()
    {
        if(head==NULL)
        {
            cout<<"All elements are cleared";
            return;
        }
        else
        {
            Node *temp;
            while(head!=NULL)
            {
                temp=head;
                head=head->next;
                delete temp;
            }
            cout<<"All elements are cleared"<<endl;
        }
    }
    int delete_by_val(int v)
    {
        if(head->val==v)
        {
            return pop_front();
        }
        Node * temp;
        temp = head;
        while(temp!=NULL)
        {
            if(temp->next->val == v)
            {
                Node * temp3 = temp->next;
                temp->next = temp->next->next;
                int ret = temp3->val;
                delete temp3;
                return ret;
            }
            temp = temp ->next;
        }
    }
    Node* get_head()
    {
        return head;
    }
    ~Linkedlist()
    {
        dispose();
    }
};
class Queue
{
    Linkedlist s1;
public:
    void push_back(int v)
    {
        s1.push_back(v);
    }
    int pop_front()
    {
        return s1.pop_front();
    }
    void display()
    {
        s1.display();
    }
    /*~Queue()
    {
        s1.dispose();
    }*/
};
int compare(Node* n1,Node* n2)
{
    Node* temp1=n1;
    Node* temp2=n2;
    int x1=0;
    while(temp1!=NULL)
    {
        x1++;
        temp1=temp1->next;
    }
    int x2=0;
    while(temp2!=NULL)
    {
        x2++;
        temp2=temp2->next;
    }
    //cout<<x1<<" "<<x2<<endl;
    if(x1==x2)
    {
        int count=0;
        temp1=n1;
        temp2=n2;
        while(temp1!=NULL)
        {
            if(temp1->val==temp2->val)
            {
                count++;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(count==x1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
void merge(Linkedlist &l1,Linkedlist &l2)
{
    Linkedlist l3;
    Node* temp1=l1.get_head();
    Node* temp2=l2.get_head();
    while(temp1!=NULL)
    {
        l3.push_front(temp1->val);
        l3.push_front(temp2->val);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    l3.display();
}
int main()
{
    Linkedlist list1,list2;
    //list1.push_front(10);
    //list1.push_front(11);
    list1.push_front(1);
    list1.push_front(3);
    list1.push_front(5);
    list1.push_front(7);
    list2.push_front(2);
    list2.push_front(4);
    list2.push_front(6);
    list2.push_front(8);
    //list1.push_front(10);
    //list1.push_front(11);
    //cout<<list1.get_size(list1.get_head())<<endl;
    //cout<<list2.get_size(list2.get_head())<<endl;
    //cout<<compare(list1.get_head(),list2.get_head())<<endl;
    //list1.push_front(11);
    //list1.push_front(20);
    //list1.push_front(40);
    //list1.display();
    //cout<<list1.pop_front()<<" Has been popped"<<endl;
    //list1.push_back(20);
    //list1.push_back(40);
    //list1.reverse();
    //cout<<list1.get_node(2)<<" is The adress"<<endl;
    //list1.delete_by_node(list1.get_node(2));
    //list1.delete_duplicate();
    //merge(list2,list1);
    //list1.push_after_node(list1.get_node(2),5);
    //list1.push_before_node(list1.get_head(),5);
//    list1.merge(list2);
    list1.display();
    cout<<list1.delete_by_val(7)<<" Has been popped!!\n";
    list1.display();

   // list1.dispose();
    /*Queue q1;
    q1.push_back(10);
    q1.push_back(20);
    q1.push_back(30);
    q1.push_back(40);
    q1.push_back(50);
    q1.display();
    q1.pop_front();
    q1.pop_front();
    q1.pop_front();
    q1.display();*/
}
