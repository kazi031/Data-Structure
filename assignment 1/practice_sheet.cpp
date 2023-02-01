#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct ArrayList
{
    int size=0;
    int capacity,i_capacity;
    int *p=NULL;
    /*INIT*/
    void initialization(int capacity_)
    {
        p=(int*)malloc(capacity_*sizeof(int));
        capacity=i_capacity=capacity_;
        printf("\ncap=%d,i_cap=%d,capacity_=%d\n",capacity,i_capacity,capacity_);
    }
    /*PUSH_BACK*/
    void push_back(int value)
    {
        p[size]=value;
        size=size+1;
        if(size==capacity)
        {
            capacity=capacity+i_capacity;
            p=(int*)realloc(p,capacity);
        }
        printf("size=%d,capacity=%d\n",size,capacity);
    }
    /*DELETE ANY POSITION*/
    void delete_any_pos(int index)
    {
        printf("size=%d,capacity=%d\n",size,capacity);
        for(int i=index;i<size;i++)
        {
            p[i]=p[i+1];
        }
        delete_last();
        cout<<endl;
        print_all();
    }
    /*REVERSE*/
    int reverse()
    {
        int count=size-1;
        for(int i=0;i<=size/2;i++)
        {
            int temp=p[i];
            p[i]=p[count];
            p[count]=temp;
            count--;
        }
    }
    /*DELETE FIRST*/
    void delete_first()
    {
        /*for(int i=0;i<size;i++)
        {
            p[i]=p[i+1];
            printf("\np[i]=%d\n",p[i]);
        }*/
        reverse();
        print_all();
        delete_last();
        cout<<endl;
        print_all();
    }
    /*DELETE LAST*/
    void delete_last()
    {
        size=size-1;
        printf("\ncap=%d,i_cap=%d,size=%d\n",capacity,i_capacity,size);
        if(capacity-size>=i_capacity)
        {
            capacity=capacity-i_capacity;
            printf("\ncap=%d,i_cap=%d,size=%d\n",capacity,i_capacity,size);
            p=(int*)realloc(p,capacity);
        }
        printf("size=%d,capacity=%d\n",size,capacity);

    }
    /*PRINT ALL*/
    void print_all()
    {
        //printf("##~");
        for(int i=0;i<size;i++)
        {
            cout<<p[i]<<" ";
        }
        printf("\n");
    }
    /*DISPOSE*/
    void dispose()
    {
        delete [] p;
    }
};

int main()
{
    //int size;
    int num,x;
    int index;
    cin>>index;
    ArrayList list1;
    /*INIT*/
    list1.initialization(index);
    for(int i=0;i<index;i++)
    {
        cin>>num;
        list1.push_back(num);
    }
    list1.print_all();
    /*DELETE FIRST*/
    printf("\nDELETE FIRST\n");
    list1.delete_first();
    /*DELETE ANY POSITION*/
    printf("\nDELETE ANY POS\n");
    cout<<"\nEnter index no:";
    cin>>index;
    list1.delete_any_pos(index);
    /*DISPOSE*/
    list1.dispose();
}
