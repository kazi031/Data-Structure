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

    int ite_binary_search(int value)
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

    }

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

    printf("\n\nOptions:\n1.Add an Element\n2.Remove an Element\n3.Search for an element using Linear Search\n4.Search for an element using Iterative Binary Search\n5.Search for an element using Recursive Binary Search\n6.Exit");
     printf("\nEnter Option:");
        //scanf("%d",&b);

    //while(b>=1&&b<=6)
    while(scanf("%d",&b),b!=6)
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

            int c=l1.ite_binary_search(a);
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
    }
    l1.Exit();

    return 0;
}



