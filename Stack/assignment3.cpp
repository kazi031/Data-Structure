#include<iostream>
#define icap 10
using namespace std;
int size=0;
int *arr=NULL;
void init(int cap)
{
    arr=new int[cap];
}
void push_at_top(int element)
{
    arr[size]=element;
    if (size==icap);
    size=size+1;
}
void pop_from_top()
{
    if(size==0)
        cout<<"stack is empty";
    else
        size=size-1;
}
int is_Empty()
{
    if(size==0)
        return 1;
    else
        return 0;
}
int is_Full()
{
    if(size==5)
        return 1;
    else
        return 0;
}
int search(int value)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==value)
            return 1;
    }
    return -1;
}
int peek_elem()
{
    return arr[size-1];
}
int get_size()
{
    return size;
}
void print_all()
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void dispose()
{
    delete [] arr;
}
int main()
{
    int icap;
    init(icap);
    push_at_top(5);
    push_at_top(4);
    push_at_top(11);
    push_at_top(25);
    push_at_top(1);
    print_all();
    pop_from_top();
    print_all();
    dispose();
}
