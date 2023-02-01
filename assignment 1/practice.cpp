#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct ArrayList
{
    int *p=NULL;
    int cap,icap;
    int size=0;
    void init(int cap_)
    {
        p=new int [cap_];/*p=(int*)malloc(cap_*sizeof(int))*/
        cap=icap=cap_;
    }
    void push_back(int value)
    {
        p[size]=value;
        size=size+1;
        if(size==cap)
        {
            cap=cap+icap;
            p=(int*)realloc(p,cap*sizeof(int));
        }
    }
    void push_front(int value)
    {
        size=size+1;
        if(size==cap)
        {
            cap=cap+icap;
            p=(int*)realloc(p,cap*sizeof(int));
        }
        for(int i=size;i>0;i--)
        {
            p[i]=p[i-1];
        }
        p[0]=value;
    }
    void push_in_between(int index,int value)
    {
        size=size+1;
        if(size==cap)
        {
            cap=cap+icap;
            p=(int*)realloc(p,cap*sizeof(int));
        }
        for(int i=size;i>index;i--)
        {
            p[i]=p[i-1];
        }
        p[index]=value;
    }
    void reverse_from_index(int a,int b)
    {

        for(int i=0;i<b;i++)
    }
    void delete_last()
    {
        size=size-1;
        if(cap-size>=icap)
        {
            cap=cap-icap;
        }
        p=(int*)realloc(p,cap*sizeof(int));

    }
    void delete_first()
    {
        for(int i=0;i<size;i++)
        {
            p[i]=p[i+1];
        }
        delete_last();
    }
    void delete_any(int index)
    {
        for(int i=index;i<size;i++)
        {
            p[i]=p[i+1];
        }
        delete_last();
    }
    void dispose()
    {
        delete [] p;
    }
    void print_all()
    {
        cout<<"The Resultant Array is:";
        for(int i=0;i<size;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    ArrayList list1;
    int cap,num,index;
    cout<<"Enter The Size of the array>>";
    cin>>cap;
    list1.init(cap);
    for(int i=0;i<cap;i++)
    {
        cin>>num;
        list1.push_back(num);
    }
    list1.print_all();
    cout<<"Enter number:>>";
    cin>>num;
    list1.push_front(num);
    list1.print_all();
    cout<<"Enter Index";
    cin>>index;
    cout<<"Enter number:>>";
    cin>>num;
    list1.push_in_between(index,num);
    list1.print_all();
    printf("Delete last>>\n");
    list1.delete_last();
    list1.print_all();
    printf("Delete first>>\n");
    list1.delete_first();

    list1.print_all();
    printf("Delete first>>\n");
    printf("Enter Index no.");
    cin>>index;
    list1.delete_any(index);
    list1.print_all();
    list1.dispose();
}
