#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct ArrayList
{
    int *p=NULL;
    int *temp=NULL;
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
    void push_forward(int value)
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
        if(index<size)
        {
            for(int i=size;i>index+1;i--)
            {
                p[i]=p[i-1];
            }
            p[index-1]=value;
        }
        else
        {
            cout<<"Invalid Index"<<endl;
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
    void delete_first()
    {
        for(int i=0;i<size;i++)
        {
            p[i]=p[i+1];
        }
        delete_last();
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
    void delete_any_pos(int index)
    {
        if(index<size)
        {
            for(int i=index-1;i<size;i++)
            {
                p[i]=p[i+1];
            }
            delete_last();
        }
        else
        {
            cout<<"Invalid Index"<<endl;
        }
    }
    void update_value(int index,int value)
    {
        if(index<size)
        {
            p[index-1]=value;
        }
        else
        {
            cout<<"Invalid Position"<<endl;
        }
    }
    int bound_check(int index)
    {
        if(index>=size)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    void isolate()
    {
        int count=0;
        temp=new int[size];
        for(int i=0;i<size;i++)
        {
            if(p[i]%2==0)
            {
                temp[count]=p[i];
                count++;
            }
        }
        for(int i=0;i<size;i++)
        {
            if(p[i]%2!=0)
            {
                temp[count]=p[i];
                count++;
            }
        }
        for(int i=0;i<size;i++)
        {
            p[i]=temp[i];
        }
        delete [] temp;

    }
    void duplicate()
    {
        temp=new int[size];
        for(int i=0;i<size;i++)
        {
            temp[i]=p[i];
        }
        size=size*2;
        if(size>=cap)
        {
            cap=cap+icap;
            p=(int*)realloc(p,cap*sizeof(int));
        }
        int count=0;
        for(int i=0;i<size;i=i+2)
        {
            p[i+2]=temp[count+1];
            count++;
        }
        for(int i=0;i<size;i=i+2)
        {
            p[i+1]=p[i];
        }
        delete [] temp;

    }
    void dispose()
    {
        delete [] p;
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
    cout<<"\n\n\t\t\t\t1. Insert element at the first position of the array"<<endl;
    cout<<"\t\t\t\t2. Insert element at the last position of the array"<<endl;
    cout<<"\t\t\t\t3. Insert element at any position of the array"<<endl;
    cout<<"\t\t\t\t4. Delete an element from the first position of the array"<<endl;
    cout<<"\t\t\t\t5. Delete an element from the last position of the array"<<endl;
    cout<<"\t\t\t\t6. Delete an element from any position of the array"<<endl;
    cout<<"\t\t\t\t7. Update any value of any position of the array"<<endl;
    cout<<"\t\t\t\t8. Isolate the odd and even number in the list"<<endl;
    cout<<"\t\t\t\t9. Duplicate"<<endl;
    cout<<"\t\t\t\t8. Quit\n"<<endl;
    cout<<"Choose Your Option >>";
    while(scanf("%d",&x),x!=10)
    {
        if(x==1)
        {
            cout<<endl<<"Please Input a number:";
            cin>>value;
            list1.push_forward(value);
            cout<<"The resultant array:";
            list1.print_all();
            cout<<"Choose Your Option >>";
        }
        if(x==2)
        {
            cout<<endl<<"Please Input a number:";
            cin>>value;
            list1.push_back(value);
            cout<<"The resultant array:";
            list1.print_all();
            cout<<"Choose Your Option >>";
        }
        if(x==3)
        {
            main1:
            cout<<endl<<"Input Positin no.:";
            cin>>index;
            c=list1.bound_check(index);
            if(c==-1)
            {
                printf("\nIvalid Position!\n");
                goto main1;
            }
            else if(c==1)
            {
                cout<<endl<<"Please Input a number:";
                cin>>value;
                list1.push_in_between(index,value);
                cout<<"The resultant array:";
                list1.print_all();
            }
            cout<<"Choose Your Option >>";
        }
        if(x==4)
        {
            list1.delete_first();
            cout<<"The resultant array:";
            list1.print_all();
            cout<<"Choose Your Option >>";
        }
        if(x==5)
        {
            list1.delete_last();
            cout<<"The resultant array:";
            list1.print_all();
            cout<<"Choose Your Option >>";
        }
        if(x==6)
        {
            main2:;
            cout<<endl<<"Input Position no.:";
            cin>>index;
            c=list1.bound_check(index);
            if(c==-1)
            {
                printf("\nIvalid position!\n");
                goto main2;
            }
            else if(c==1)
            {
                list1.delete_any_pos(index);
                cout<<"The resultant array:";
                list1.print_all();
            }
            cout<<"Choose Your Option >>";
        }
        if(x==7)
        {
            main3:;
            cout<<endl<<"Input Positon no.:";
            cin>>index;
            c=list1.bound_check(index);
            if(c==-1)
            {
                printf("\nIvalid Index!\n");
                goto main3;
            }
            else if(c==1)
            {
                cout<<"Please Input Value:";
                cin>>value;
                list1.update_value(index,value);
                cout<<"The resultant array:";
                list1.print_all();
            }
            cout<<"Choose Your Option >>";
        }
        else if(x==8)
        {
            cout<<"isolate>>";
            list1.isolate();
            cout<<"The resultant array:";
            list1.print_all();
            cout<<"Choose Your Option >>";
        }
        else if(x==9)
        {
            cout<<"Duplicate>>";
            list1.duplicate();
            cout<<"The resultant array:";
            list1.print_all();
            cout<<"Choose Your Option >>";
        }
    }
    list1.dispose();
}
