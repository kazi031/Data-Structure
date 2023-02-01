#include<iostream>
#include<stdio.h>
using namespace std;
void bubble_sort(int arr[],int size);
void linear_sort(int arr[],int size);
void insertion_sort(int arr[],int size);
int main()
{
    int arr[5]={15,10,5,4,3};
    ///bubble_sort(arr,5);
//    insertion_sort(arr,5);
//    for(int i=0;i<5;i++)
//    {
//        cout<<arr[i]<<" ";
//    }
    bubble_sort(arr,5);
}
void bubble_sort(int arr[],int size)
{
    int count = 0;
    bool swapped=true;
    while(swapped==true)
    {
        count++;
        ///int c=0;
        swapped=false;
        for(int i=0;i<size-1;i++)
        {

            if(arr[i]>arr[i+1])
            {
                /*int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;*/
               swap(arr[i],arr[i+1]);
                ///c++;
                swapped=true;
            }
        }
        /*if(c!=0)
        {
            swap=true;
        }
        else
        {
            swap=false;
        }*/
    }
    printf("%d\n",count);

}
void linear_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
}
void insertion_sort(int arr[],int size)
{
    int key,j;
    for(int i=1;i<size;i++)
    {
        key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key)
        {
            //swap(arr[i],arr[j]);
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
