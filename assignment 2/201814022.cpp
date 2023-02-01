#include<iostream>
#include<cstdlib>
#include<cstdio>
#define iCap 4


using namespace std;

struct SortedList
{
    int size=0,capacity,value;
    int *List=NULL;

    void init()
    {
        List=(int *)malloc(sizeof(int)*iCap);
        capacity=iCap;

    }

    void expand()
    {
        int *temp,i;
        capacity=capacity<<1;
        temp=(int *)malloc(sizeof(int)*capacity);
        for(i=0;i<size;i++)
            temp[i]=List[i];
        free(List);
        List=temp;
    }

    void shrink()
    {
        int *temp,i;
        if(capacity==iCap)
            return;
        capacity=capacity>>1;
        temp=(int *)malloc(sizeof(int)*capacity);
        for(i=0;i<size;i++)
            temp[i]=List[i];
        free(List);
        List=temp;

    }

    void printAll()
    {
        int i;

        for(i=0;i<size;i++)
            printf("%d ",List[i]);
        printf("\n");
    }

    int insert(int value)
    {
        if(size>=capacity)
            expand();
        for(int i=0;i<size;i++)
        {
            if(List[i]>=value)
            {
               if(List[i]>value)
               {
                for(int j=size;j>i;j--)
                    List[j]=List[j-1];

                List[i]=value;
                size++;
                return i;
               }
               else
                return i;
            }
        }

        List[size]=value;
        size++;
        return size-1;
    }


    int remove(int value)
    {
       for(int i=0;i<size;i++)
       {
           if(List[i]==value)
           {
               for(int j=i;j<size;j++)
                List[j]=List[j+1];
               size--;
               if((capacity-size)==(iCap+1))
                shrink();
               return i;
           }
       }
       return -1;
    }

    int linear_search(int value)
    {
        for(int i=0;i<size;i++)
        {
            if(List[i]==value)
                return i;
        }

        return -1;
    }





    int binary_search(int num)
    {
        int last=size-1;
        int first=0;
        int mid=(last+first)/2;
        while(first<=last)
        {
            if(List[mid]<num)
            {
                first=mid+1;
            }
            else if(List[mid]==num)
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









    /*int ite_binary_search(int value)
    {
        int mid,i=0,j=size;

        while(i<=j)
        {

            int mid = (i+(j-1))/2;

            if(List[mid]==value)
                return mid;
            if(List[mid]<value)
                i=mid+1;
            else
                j=mid-1;


        }

        return -1;

    }*/

    int rec_binary_search(int value,int i,int j)

    {


        if(j>=i)
        {
            int mid=(i+(j-1))/2;

            if(List[mid]==value)
                return mid;
            if(List[mid]>value)
                return rec_binary_search(value,i,mid-1);
            else
                return rec_binary_search(value,mid+1,j);
        }

        return -1;


    }
    int number_search(int element)
    {
        int c=binary_search(element);
        //cout<<endl<<c<<endl;
        if(c==-1)
        {
            if(List[0]>element)
            {
                return List[0];
            }
            int p1=getSize();
            for(int i=1;i<p1;i++)
            {
                if(List[i]>element)
                {
                    int a=List[i]-element;
                    int b=element-List[i-1];
                    if(b<a)
                    {
                        return List[i-1];
                    }
                    else
                    {
                        return List[i];
                    }
                }
            }
        }
        else
        {
            return c;
        }
     }
     /*int array_sum(int element)
     {
         for(int i=0;i<size;i++)
         {
             for(int j=i+1;j<size;j++)
             {
                 if(p[i]+p[j]==element)
                 {
                     return element;
                 }
             }
         }
         return -1;
     }*/
     int array_sum(int element)
     {
         int c=element;
         for(int i=0;i<=element/2;i++)
         {
             if(i+c==element)
             {
                 if((binary_search(i)&& binary_search(c))!=-1)
                    return 1;
             }
             c--;
         }
        return -1;
     }
    void Exit()
    {
        free(List);
        exit(0);
    }

    int getSize()
    {
        return size;
    }
};


int main()
{
    SortedList l1;

    int value,a,b;

    l1.init();
    printf("\nEnter the elements of the list: ");
    for(int i=0;i<4;i++)
    {
        scanf("%d",&a);
        l1.insert(a);
    }
    l1.printAll();

    printf("\n\nOptions:\n1.Add an Element\n2.Remove an Element\n3.Search for an element using Linear Search\n4.Search for an element using Iterative Binary Search\n5.Search for an element using Recursive Binary Search\n6.number search\n8.ArraySum\n9.exit\n");
     printf("\nEnter Option:");
        //scanf("%d",&b);

    while(scanf("%d",&b),b!=8)
    {
        if(b==1)
        {
            printf("Enter element: ");
            scanf("%d",&a);
            int c = l1.insert(a);
            printf("%d is in index no.%d\n",a,c);
            l1.printAll();
            printf("\nEnter Option:");
        }
        if(b==2)
        {
            printf("Enter element: ");
            scanf("%d",&a);
            int c=l1.remove(a);
            if(c!=-1)
            printf("%d has been removed from index no.%d\n",a,c);
            else
            printf("%d is not present in the list\n",a);
            l1.printAll();
            printf("\nEnter Option:");
        }
        if(b==3)
        {
            printf("Enter element: ");
            scanf("%d",&a);
            int c=l1.linear_search(a);
            if(c!=-1)
            printf("%d is in index no.%d",a,c);
            else
                printf("%d is not present in the list",a);
            printf("\nEnter Option:");

        }
        if(b==4)
        {
            printf("Enter element: ");
            scanf("%d",&a);

            int c=l1.binary_search(a);
            if(c!=-1)
            printf("%d is in index no.%d",a,c);
            else
                printf("%d is not present in the list",a);
            printf("\nEnter Option:");
        }
        if(b==5)
        {
            printf("Enter element: ");
            scanf("%d",&a);
            int c=l1.getSize();
            int d=l1.rec_binary_search(a,0,c);
            if(d!=-1)
            printf("%d is in index no.%d",a,d);
            else
                printf("%d is not present in the list",a);
            printf("\nEnter Option:");
        }
        if(b==6)
        {
            cout<<"enter the element you want to search>>";
            cin>>a;
            int k1=l1.number_search(a);
            cout<<endl<<"number search output:"<<k1;
            printf("\nEnter Option:");
        }
        if(b==7)
        {
            cout<<"enter the sum of elements you want to search>>";
            cin>>a;
            int k2=l1.array_sum(a);
            if(k2!=-1)
            {
                cout<<"\nYes\n";
            }
            else
            {
                cout<<"\nNo\n";
            }
            printf("\nEnter Option:");
        }

        //printf("\nEnter Option:");
    }
    l1.Exit();

    return 0;
}






