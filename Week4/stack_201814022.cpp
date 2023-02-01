#include<iostream>
#define icap 10
using namespace std;
class Stack
{
    int top;
    int p[icap];
public:
    Stack()
    {
        top=-1;
    }
    bool isFull()
    {
        if(top==icap-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push_top(int v)
    {
        if(isFull()==1)
        {
            cout<<"The Stack is Full";
        }
        else
        {
            top++;
            p[top]=v;
        }
    }
    int pop_top()
    {
        if(top==-1)
        {
            cout<<"The Stack is empty";
        }
        else
        {
            int t=p[top];
            top--;
            return t;
        }
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        if(isEmpty()==0)
        {
            cout<<"Resultant Array:"<<endl;
            for(int i=0;i<=top;i++)
            {
                cout<<p[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"The Stack is Empty";
        }
    }
    void push_bottom(int v)
    {
        int arr[icap];
        int temp=top;
        if(top==-1)
        {
            push_top(v);
        }
        else
        {
            for(int i=0;i<=temp;i++)
            {
                arr[i]=pop_top();
            }
            push_top(v);
            for(int i=temp;i>=0;i--)
            {
                push_top(arr[i]);
            }
        }
    }
    int pop_bottom()
    {
        int arr[top];
        if(top==-1)
        {
            cout<<"Stack is empty";
            return -1;
        }
        else
        {
            int temp=top;
            for(int i=0;i<temp;i++)
            {
                arr[i]=pop_top();
            }
            int t=pop_top();
            for(int i=temp-1;i>=0;i--)
            {
                push_top(arr[i]);
            }
            return t;
        }
    }
    int search(int val)
    {
        for(int i=0;i<=top;i++)
        {
            if(p[i]==val)
            {
                return i+1;
            }
        }
        return -1;
    }
    int get_top()
    {
        return top;
    }
    int get_peek()
    {
        return p[top];
    }
};
int main()
{
    cout<<"1. Push element at the top of the Stack"<<endl;
    cout<<"2. Push element at the bottom of the Stack"<<endl;
    cout<<"3. Pop element from the top of the Stack"<<endl;
    cout<<"4. Pop element from the bottom of the Stack"<<endl;
    cout<<"5. Print the Stack"<<endl;
    cout<<"6. Show the peek element of the Stack"<<endl;
    cout<<"7. Search an element in the Stack and show its position"<<endl;
    cout<<"8. Quit"<<endl;
    Stack s1;
    int x;
    cout<<"Enter option:";
    while(cin>>x,x!=8)
    {
        if(x==1)
        {
            int val;
            cout<<"Enter value:";
            cin>>val;
            s1.push_top(val);
            cout<<endl<<"Enter option:";
        }
        if(x==2)
        {
            int val;
            cout<<"Enter value:";
            cin>>val;
            s1.push_bottom(val);
            cout<<endl<<"Enter option:";
        }
        if(x==3)
        {
            cout<<s1.pop_top()<<" Has been deleted"<<endl;
            cout<<endl<<"Enter option:";
        }
        if(x==4)
        {
            cout<<s1.pop_bottom()<<" Has been deleted"<<endl;
            cout<<endl<<"Enter option:";
        }
        if(x==5)
        {
            s1.display();
        }
        if(x==6)
        {
            cout<<s1.get_peek()<<" is the top element"<<endl;
        }
        if(x==7)
        {
            int val;
            cin>>val;
            if(s1.search(val)!=-1)
            {
                cout<<"Found in Position:"<<s1.search(50);
            }
            else
            {
                cout<<"Not Found";
            }
        }
    }
}
