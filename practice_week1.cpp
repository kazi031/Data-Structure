#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
struct ArrayList
{
    int *p=NULL;
    int size=0;
    int cap,icap;
    void init(int cap_)
    {
        p=new int[cap_];
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
    void print_all()
    {
        for(int i=0;i<size;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
    void dispose()
    {
        delete [] p;
    }
    void left_rotation(int time)
    {
        for(int j=0;j<time;j++)
        {
            size=size+1;
            p[size-1]=p[0];
            for(int i=0;i<=size;i++)
            {
                p[i]=p[i+1];
            }
            size=size-1;
        }

    }

};
int main()
{

    ArrayList list1;
    int cap,value,x,index,c;
    cout<<"Enter the size of the array:";
    cin>>cap;
    list1.init(cap);
    for(int i=0;i<cap;i++)
    {
        cout<<i+1<<"No. position:";
        cin>>value;
        list1.push_back(value);
    }
    cout<<"The resultant array:";
    list1.print_all();
    list1.left_rotation(3);
    list1.print_all();
    list1.dispose();
}
