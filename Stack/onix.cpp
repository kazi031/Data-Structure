#include<iostream>
#include<cstdio>
#define MAX 10
using namespace std;
struct Stack
{
    int arr[MAX];
    int top;
    Stack()
    {
        top=-1;
    }
    bool isFull()
    {
        if(top==MAX-1)
            return 1;
        else
            return 0;
    }
    void push(int value)
    {
        if(isFull()==1)
        {
            cout<<"Stack is full"<<endl;

        }
        else
        {
            top++;
            arr[top]=value;
        }
    }
    int pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else
        {
            int t=arr[top];
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
            return 0;
    }
    void print_all()
    {
        if(!isEmpty())
        {
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else
            cout<<"Stack is empty";
    }
    int peek()
    {
        if(!isEmpty())
            return arr[top];
        else
            return -1;
    }
};
int main()
{
    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout<<"Top Element:"<<s1.peek();
}















