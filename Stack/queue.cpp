#include<iostream>
#define icap 10
using namespace std;
template <class T>
class Queue
{
    //int MAX=10;
    T arr[icap];
    int rear;
    int front;
    int total_cap;
    int cur_num_of_elem=0;
public:
    Queue()
    {
        rear=0;
        front=0;
    }
    void enqueue(T val)
    {
        if(isFull()==1)
        {
            cout<<"Queue is full";
        }
        else
        {
            arr[rear]=val;
            rear=rear+1;
            cur_num_of_elem++;
        }
    }
    void display_queue()
    {
        cout<<"Displaying the queue:"<<endl;
        for(int i=0;i<cur_num_of_elem;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    T dequeue()
    {
        T a=arr[front];
        front++;
        cur_num_of_elem--;
        return a;
    }
    int isFull()
    {
        if(cur_num_of_elem==icap-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    Queue<char> ob;
    ob.enqueue('a');
    ob.enqueue('b');
    ob.enqueue('c');
    ob.enqueue('d');
    /*for(int i=0;i<5;i++)
    {
        T x;
        cin>>x;
        ob.enqueue(x);
    }*/
    ob.display_queue();
    //ob.dequeue();
    //ob.display_queue();
}
