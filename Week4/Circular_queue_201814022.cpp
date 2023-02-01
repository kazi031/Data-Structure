#include<iostream>
#define icap 10
using namespace std;
class C_Queue
{
    int arr[icap];
    int rear;
    int front;
    int size;
public:
    C_Queue()
    {
        rear=0;
        front=0;
        size=0;
    }
    void enqueue(int val)
    {
        if(get_size()==icap)
        {
            cout<<"Queue is full";
        }
        else
        {
            if(rear%icap==0)
            {
                rear=0;
            }
            arr[rear]=val;
            rear=rear+1;
            size++;
        }
    }
    int dequeue()
    {
        if(front==icap)
        {
            front=0;
        }
        else
        {
            int a=arr[front];
            size--;
            front++;
            display_queue();
            return a;
        }
    }
    int get_size()
    {
        return size;
    }
    void display_queue()
    {
        if(rear>front)
        {
            cout<<"Displaying the queue:"<<endl;
            for(int i=front;i<rear;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            cout<<"Displaying the queue:"<<endl;
            for(int i=front;i<icap;i++)
            {
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<rear;i++)
            {
                cout<<arr[i]<<" ";
            }
        }
    }
};
int main()
{
    C_Queue ob;
    ob.enqueue(10);
    ob.enqueue(20);
    ob.enqueue(30);
    ob.enqueue(50);
    ob.enqueue(60);
    ob.enqueue(70);
    ob.enqueue(50);
    ob.enqueue(22);
    ob.enqueue(23);
    ob.enqueue(24);
    ob.display_queue();
    ob.dequeue();
    ob.dequeue();
    ob.dequeue();
    ob.dequeue();
    ob.enqueue(44);
    ob.display_queue();
}
