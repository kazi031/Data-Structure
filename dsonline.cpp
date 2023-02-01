#include<iostream>
using namespace std;
struct Node
{
    int val;
    Node* next;
};
class SingleLinkedList
{
    Node* head;
public:
    SingleLinkedList()
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
            head->next=NULL;
        }
        else
        {
            temp->next=head;
            head=temp;
        }
    }
    Node* get_head()
    {
      return head;
    }
    void delete_same_val()
    {
      if(head==NULL)
       {
           cout<<"This list is empty"<<endl;
       }
       else if(head->next==NULL)
       {
           cout<<"not possible"<<endl;
       }
       else
        {
           Node* temp=head;
           Node* temp2=head;
           Node* temp3=head;
           Node* temp4=new Node;
           while(temp->next!=NULL)
             {
                temp2=temp->next;
                while(temp2!=NULL)
                {
                   if(temp->val==temp2->val)
                    {
                       while(temp3->next!=temp2)
                        {
                          temp3=temp3->next;
                        }
                       temp4=temp2;
                       temp3->next=temp2->next;
                       temp2=temp2->next;
                       delete temp4;
                   }
                   else
                     {
                       temp2=temp2->next;
                     }
              }
              if(temp->next==NULL)
              {
                  return;
              }
              temp=temp->next;
           }

       }
    }
   /* int compare(Node* headA,Node* headB)
    {
        Node* temp=headA;
        Node* temp2=headB;
        int n1=0;
        int n2=0;
        while(temp!=NULL)
        {
            n1=n1+1;
            temp=temp->next;
        }
        while(temp2!=NULL)
        {
            n2=n2+1;
            temp2=temp2->next;
        }
        if(n1==n2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        {
            while(temp!=NULL && temp2!=NULL)
            {
              if(temp->val!=temp2->val)
              {
                  return 0;
              }
            else if(temp->val==temp2->val)
                {
                    temp=temp->next;
                    temp2=temp2->next;
                }
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }*/
    Node* get_node(int a)
    {
        Node* temp=head;
        for(int i=1;i<a;i++)
        {
            temp=temp->next;
        }
        return temp;
    }
    void push_after_node(Node* node,int v)
    {
        Node* temp=node;
        Node* temp2=new Node;
        temp2->next=NULL;
        temp2->val=v;
        temp2->next=node->next;
        node->next=temp2;
    }
    void push_before_node(Node* node,int v)
    {
        if(node==head)
        {
            push_front(v);
        }
        else
        {
            Node* temp=node;
            Node* temp2=new Node;
            temp2->next=NULL;
            temp2->val=v;
            Node* temp3=head;
            while(temp3->next!=node)
             {
               temp3=temp3->next;
             }
           temp2->next=node;
           temp3->next=temp2;
        }
    }
    void merge(SingleLinkedList l2)
    {
        Node* temp=head;
        Node* temp2=l2.get_head();
        while(temp!=NULL)
        {
            Node* temp3=temp;
            temp=temp->next;
            push_before_node(temp3,temp2->val);

            temp2=temp2->next;
        }
    }
    void display()
    {
         Node* temp=head;
         if(head==NULL)
        {
            cout<<"This list is empty"<<endl;
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
    void dispose()
    {
        while(head!=NULL)
        {
            Node* temp;
            temp=head;
            head=head->next;
            delete temp;
        }
    }
    ~SingleLinkedList()
    {
        dispose();
        cout<<"The list is cleared"<<endl;
    }

};
 int compare(Node* headA,Node* headB)
    {
        Node* temp=headA;
        Node* temp2=headB;
        int n1=0;
        int n2=0;
        while(temp!=NULL)
        {
            n1=n1+1;
            temp=temp->next;
        }
        while(temp2!=NULL)
        {
            n2=n2+1;
            temp2=temp2->next;
        }
        if(n1==n2)
        //{
            //return 1;
       // }
        //else
        //{
            //return 0;
       // }
        {
             int c=0;
             int d=0;
             temp=headA;
             temp2=headB;
            while(temp!=NULL)
            {

              if(temp->val!=temp2->val)
              {
                  c=c+1;
              }
             else if(temp->val==temp2->val)
                {
                   d=d+1;
                }

                  temp=temp->next;
                  temp2=temp2->next;
            }
                if(d==n1)
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
   /* void merge(Node* headA,Node* headB)
    {
        Node* temp=headA;
        Node* temp2=headB;
        Node* temp3=headA->next;
        Node* temp4=headB->next;

        while(temp->next!=NULL)
        {
            temp->next=temp2;
            temp2->next=temp3;
            temp3->next=temp4;
            temp3=temp3->next;
            temp4=temp4->next;
        }
        Node* a=temp;
        while(a!=NULL)
        {
            cout<<a->val<<" ";
            a=a->next;
        }
    }*/
int main()
{
    SingleLinkedList l1,l2;
    l1.push_front(50);
    l1.push_front(40);
    l1.push_front(30);
    l1.push_front(20);
    l1.push_front(10);
    //l1.display();
    l2.push_front(50);
    l2.push_front(40);
    l2.push_front(30);
    l2.push_front(20);
    l2.push_front(10);
    //l2.display();
    //cout<<compare(l1.get_head(),l2.get_head())<<endl;
    //merge(l1.get_head(),l2.get_head());
    //l1.push_after_node(l1.get_head(),5);
    //l1.display();
    //l1.push_before_node(l1.get_node(2),6);
    //l1.display();
    l1.merge(l2);
    l1.display();




    //l1.delete_same_val();
    //l1.display();
}
