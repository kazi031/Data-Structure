#include<iostream>
#include<cstdlib>
using namespace std;
struct ArrayList
{
    int * p=NULL;
    int icapacity;
    int capacity;
    int size=0;
    void init(int capacity_)
    {
        p=new int[capacity_];
        capacity=icapacity=capacity_;
    }
    void push_back(int a)
    {
        p[size]=a;
        size+=1;
        if(size==capacity)
        {
            capacity+=icapacity;
            p=(int*)realloc(p,capacity);
        }

    }
    void dispose()
    {
        delete [] p;
    }
    void print_all()
    {
        for(int i=0;i<size;i++)
            cout<<p[i]<<" ";
        cout<<endl;
    }
    void push_front(int b)
    {
        size+=1;
        if(size==capacity)
            capacity+=icapacity;
            int temp;
        for(int i=size;i>0;i--)
        {
            p[i]=p[i-1];


        }
        p[0]=b;
    }
    void update_value(int index,int value)
    {
        p[index]=value;
    }
    void add_anywhere(int index,int value)
    {
        size+=1;
        if(size==capacity)
            capacity+=icapacity;
        for(int i=size;i>index;i--)
        {
            p[i]=p[i-1];
        }
        p[index]=value;
    }
    void del_last()
    {
        size-=1;
        if(size<(capacity-icapacity))
            capacity-=icapacity;
    }
    void del_first()
    {
        for(int i=0;i<size;i++)
        {
            p[i]=p[i+1];
        }
        size-=1;
        if(size<(capacity-icapacity))
            capacity-=icapacity;
    }
    void del_from_anywhere(int index)
    {
        for(int i=index;i<size;i++)
        {
            p[i]=p[i+1];
        }
        size-=1;
        if(size<(capacity-icapacity))
            capacity-=icapacity;
    }

    int size_()
    {
        return size;
    }


};
int main()
{
    ArrayList al;
    cout<<"Enter the size of the array: ";
    int x,element;
    cin>>x;
    cout<<endl;
    al.init(x);
    cout<<"enter the elements of the array: "<<endl;
    for(int i=0;i<x;i++)
    {
        cin>>element;
        al.push_back(element);
    }
    cout<<"The resultant array : "<<endl;
    al.print_all();
    cout<<"Choose one of the options: "<<endl;
    cout<<"1.  Insert an element at the first position of the array"<<endl;
    cout<<"2.  Insert an element at the last position of the array"<<endl;
    cout<<"3.  Insert an element at any middle position of the array"<<endl;
    cout<<"4.  Delete an element from the first position of the array"<<endl;
    cout<<"5.  Delete an element from the last position of the array"<<endl;
    cout<<"6.  Delete an element from any middle position of the array"<<endl;
    cout<<"7.  Update an element"<<endl;
    cout<<"8.  Quit"<<endl;
    again:
        cout<<"Enter choice: "<<endl;
    int choice;
    int el,index;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter element: "<<endl;
        //int el;
        cin>>el;
        al.push_front(el);
        cout<<"Resultant array: "<<endl;
        al.print_all();
        goto again;
    }
    else if(choice==2)
    {

        cout<<"Enter element: "<<endl;
        cin>>el;
        al.push_back(el);
        cout<<"Resultant array: "<<endl;
        al.print_all();
        goto again;
    }
    else if(choice==3)
    {
        cout<<"Enter position: "<<endl;
        cin>>index;
        if(index>=al.size_()||index<0)
            cout<<"Invalid index"<<endl;
        else
        {


        cout<<"Enter element: "<<endl;
        cin>>el;
        al.add_anywhere(index,el);
        al.print_all();
        }
        goto again;
    }
    else if(choice==4)
    {
        cout<<"Deleting the first element from the array..."<<endl;

        al.del_first();
        cout<<"Resultant array: "<<endl;
        al.print_all();
        goto again;
    }
    else if(choice==5)
    {
        cout<<"Deleting the last element of the array..."<<endl;

        al.del_last();
        cout<<"Resultant array:"<<endl;
        al.print_all();
        goto again;
    }
    else if(choice==6)
    {
        cout<<"Enter the position of the element you want to delete: "<<endl;
        cin>>index;
        if(index>=al.size_()||index<0)
            cout<<"Invalid index"<<endl;
        else
        {


        al.del_from_anywhere(index);
        cout<<"Resultant array: "<<endl;
        al.print_all();
        }
        goto again;
    }
    else if(choice==7)
    {
        cout<<"Enter the position of the element you want to update: "<<endl;
        cin>>index;
        if(index>=al.size_()||index<0)
            cout<<"Invalid index"<<endl;
        else
        {


        cout<<"Enter the new element :"<<endl;
        cin>>el;
        al.update_value(index,el);
        cout<<"Resultant array:"<<endl;
        al.print_all();
        }
        goto again;
    }
    else if(choice==8)
        goto End;
    else
    {
        cout<<"Invalid input.See the options again and please try to be careful this time"<<endl;
        goto again;


    }
    End:

    al.dispose();
}
