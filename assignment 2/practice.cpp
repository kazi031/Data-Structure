#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cctype>
#define icap 4
using namespace std;
struct Sorted_List
{
    int *p=NULL;
    int cap;
    int length=0;
    void init()
    {
        p=new int[icap];
        cap=icap;
    }
    void quit()
    {
        delete [] p;
    }
    int insert(int element)
    {
        if(length>=cap)
        {
            expand();
        }
        for(int i=0;i<length;i++)
        {
            if(p[i]>element)
            {
                for(int j=length;j>i;j--)
                {
                    p[j]=p[j-1];
                }
                p[i]=element;
                length++;
                return i;
            }
        }
        p[length]=element;
        length++;
        return length-1;
    }
    void expand()
    {
        cap=cap+icap;
        p=(int*)realloc(p,cap*sizeof(int));
    }
    int linear_search(int element)
    {
        for (int i=0; i<length; i++)
        {
            if (p[i]==element)
            {
                return i;
            }
        }
	return -1;
    }
    int binary_search(int num)
    {
        int last=length-1;
        int first=0;
        int mid=(last+first)/2;
        while(first<=last)
        {
            if(p[mid]<num)
            {
                first=mid+1;
            }
            else if(p[mid]==num)
            {
                /*cout<<num<<" found in the array at the index no.: "<<mid<<endl;
                break;*/
                return mid;
            }
            else
            {
                last=mid-1;
            }
            mid=(last+first)/2;
        }
        return -1;
        /*if(first > last)
        {
            cout<<num<<" not found in the array";
        }*/
    }
    int binary_search(int num, int first, int last)
    {
        if (last >= first)
        {
            int mid = (first + last) / 2;

            if (num == p[mid])
            return mid;
            else if (num< p[mid])
            return binary_search(num, first, mid - 1);
            else
            return binary_search(num, mid + 1, last);
        }
        return -1;
    }

    void print_all()
    {
        for(int i=0;i<length;i++)
        {
            cout<<p[i]<<" ";
        }
    }
    int remove(int element)
    {
        for(int i=0;i<length;i++)
        {
            if(p[i]==element)
            {
                for(int j=i;j<length;j++)
                {
                    p[j]=p[j+1];
                    length--;
                    if(cap-length>=icap)
                    {
                        shrink();
                    }
                    return i;
                }
            }
        }
        return -1;
    }
    void shrink()
    {
        cap=cap-icap;
        p=(int*)realloc(p,cap*sizeof(int));
    }

};
int main()
{
    Sorted_List list1;
    list1.init();
    int num;

    for(int i=0;i<icap;i++)
    {
        cin>>num;
        //printf("###~");
        int p=list1.insert(num);
        cout<<"\nThe element was added in index no. >>"<<p<<endl;
    }
    list1.print_all();
    cout<<endl<<"Enter the number you want to search:"<<endl;
    cin>>num;
    int y=list1.linear_search(num);
    if(y!=-1)
    {
        cout<<endl<<"The element was found in index no.:"<<y;
    }
    else
    {
        cout<<endl<<"there is no such element";
    }
    cout<<endl<<"Enter the number you want to search:"<<endl;
    cin>>num;
    int c1=list1.binary_search(num);
    if(c1!=-1)
    {
        cout<<num<<" found in the array at the index no.: "<<c1<<endl;
    }
    else
    {
        cout<<num<<" not found in the array";
    }
    cout<<endl<<"Enter the number you want to search:"<<endl;
    cin>>num;
    int c2=list1.binary_search(num,0,4);
    if(c1!=-1)
    {
        cout<<num<<" found in the array at the index no.: "<<c1<<endl;
    }
    else
    {
        cout<<num<<" not found in the array";
    }
    cout<<endl<<"Enter the element you want to delete:"<<endl;
    cin>>num;
    int c3=list1.remove(num);
    if(c3!=-1)
    {
        cout<<c3<<" no. index is deleted";
    }
    else
    {
        cout<<"There is no such element";
    }
    list1.quit();
}
