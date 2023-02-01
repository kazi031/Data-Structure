#include<iostream>
using namespace std;
#define MAXSIZE 5

int s[MAXSIZE];
int top=-1;
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top==3)
        return 1;
    else
        return 0;
}
int push_front(int element)
{
    if(isFull()==1)
    {
        cout<<"The stack is full"<<endl;
    }
    else
    {
        top=top+1;
        s[top]=element;
    }
}
void pop_front()
{
    if(isEmpty()==1)
    {
        cout<<"The Stack is empty"<<endl;
    }
    else
    {
        top=top-1;
    }
}
void print_all()
{
    for(int i=0;i<=top;i++)
        cout<<s[i]<<" ";
}
int main()
{

    if(isEmpty()==1)
    {
        cout<<"The Stack is empty"<<endl;
    }
    else
    {
        cout<<"Not Empty!"<<endl;
    }
    if(isFull()==1)
    {
        cout<<"The stack is full"<<endl;
    }
    else
    {
        cout<<"The stack is not full!"<<endl;
    }
    push_front(5);
    push_front(8);
    push_front(4);
    push_front(15);
    print_all();
    pop_front();
    print_all();
}
