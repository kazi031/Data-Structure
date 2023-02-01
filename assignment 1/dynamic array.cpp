#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
struct ArrayList
{
    int size=0;
    int capacity,i_capacity;
    int *p=NULL;
    void initialization(int capacity_)
    {
        p=(int*)malloc(capacity_*sizeof(int));
        capacity=i_capacity=capacity_;
    }
    void push_back(int value)
    {
        p[size]=value;
        size=size+1;
        printf("size=%d,capacity=%d\n",size,capacity);
        if(size==capacity)
        {
            capacity=capacity+i_capacity;
            p=(int*)realloc(p,capacity);
        }
    }
    void dispose()
    {
        delete [] p;
    }
    void print_all()
    {
        //printf("##~");
        for(int i=0;i<size;i++)
        {
            cout<<p[i]<<" ";
        }
        printf("\n");
    }
    void push_forward(int value)
    {
        size=size+1;
        if(size==capacity)
        {
            capacity=capacity+i_capacity;
            p=(int*)realloc(p,capacity);
        }
        printf("size=%d,capacity=%d\n",size,capacity);
        for(int i=size;i>0;i--)
        {
            p[i]=p[i-1];
        }
        p[0]=value;
    }
    void push_in_between(int index,int value)
    {
        size=size+1;
        if(size==capacity)
        {
            capacity=capacity+i_capacity;
            p=(int*)realloc(p,capacity);
        }
        if(index<size)
        {
            for(int i=size;i>index;i--)
            {
                p[i]=p[i-1];
            }
            p[index]=value;
        }
    }
    void delete_last()
    {
        size=size-1;
        if(capacity-size==i_capacity)
        {
            capacity=capacity-i_capacity;
            p=(int*)realloc(p,capacity);
        }
    }
    void delete_first()
    {
        for(int i=0;i<size;i++)
        {
            p[i]=p[i+1];
        }
        delete_last();
        /*size=size-1;
        if(capacity-size==i_capacity)
        {
            capacity=capacity-i_capacity;
            p=(int*)realloc(p,capacity);
        }*/
    }
    void delete_any_pos(int index)
    {
        printf("size=%d,capacity=%d\n",size,capacity);
        for(int i=index;i<size;i++)
        {
            p[i]=p[i+1];
        }
        print_all();
        delete_last();
        print_all();
        /*size=size-1;
        if(capacity-size==i_capacity)
        {
            capacity=capacity-i_capacity;
            p=(int*)realloc(p,capacity);
        }*/
    }
    void update_index(int index,int value)
    {
        p[index]=value;
    }
};
int main()
{
    int size;
    int num,x;
    int index;
    cin>>size;
    ArrayList list1;
    list1.initialization(size);
    for(int i=0;i<size;i++)
    {
        cin>>num;
        list1.push_back(num);
    }
    list1.print_all();
    //system("cls");
    while(scanf("%d",&x),x!=8)
    {
        if(x==1)
        {
            printf("\nPUSH FORWARD\n");
            printf("Enter value:");
            cin>>num;
            list1.push_forward(num);
            list1.print_all();
            //system("cls");
        }
        else if(x==2)
        {
            printf("\nPUSH BACK\n");
            printf("Enter value:");
            cin>>num;
            list1.push_back(num);
            list1.print_all();
            //system("cls");
        }
        else if(x==3)
        {
            printf("\nPUSH IN BITWEEN\n");
            cout<<"Enter index no:";
            cin>>index;
            cout<<"Enter value:";
            cin>>num;
            list1.push_in_between(index,num);
            list1.print_all();
            //system("cls");
        }
        else if(x==4)
        {
            printf("\nDELETE FIRST\n");
            list1.delete_first();
            cout<<endl;
            list1.print_all();
            //system("cls");
        }
        else if(x==5)
        {
            printf("\nDELETE LAST\n");
            list1.delete_last();
            cout<<endl;
            list1.print_all();
            //system("cls");
        }
        else if(x==6)
        {
            printf("\nDELETE ANY POS\n");
            cout<<"\nEnter index no:";
            cin>>index;
            list1.delete_any_pos(index);
            list1.print_all();
            //system("cls");
        }
        else if(x==7)
        {
            printf("\nUPDATE INDEX\n");
            cout<<"\nEnter index no:";
            cin>>index;
            cout<<"Enter value:";
            cin>>num;
            list1.update_index(index,num);
            list1.print_all();
            //system("cls");
        }
        else if(x==8)
        {
            list1.dispose();
            return 0;
        }
    }
}
