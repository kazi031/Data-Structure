#include<iostream>
#include<cstdlib>
using namespace std;
class Stack
{
    char *p;
    int top;
public:
    Stack()
    {
        p=NULL;
        top=-1;
    }
    void push_top(char c)
    {
        top++;
        p=(char*)realloc(p,(top+1)*sizeof(char));
        p[top]=c;
    }
    char pop_top()
    {
        char ret=p[top];
        top--;
        p=(char*)realloc(p,(top+1)*sizeof(char));
        return ret;
    }
    void display()
    {
        if(isEmpty()==1)
        {
            cout<<"The Stack is Empty";
        }
        else
        {
            for(int i=0;i<=top;i++)
            {
                cout<<p[i]<<" ";
            }
            cout<<endl;
        }
    }
    int isEmpty()
    {
        if(top==-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void dispose()
    {
        cout<<"Clearing All elements"<<endl;
        free(p);
    }
    ~Stack()
    {
        dispose();
    }
};
int main()
{
    Stack s1;
    s1.push_top('a');
    s1.push_top('b');
    s1.push_top('c');
    s1.push_top('d');
    s1.push_top('e');
    s1.display();
    cout<<s1.pop_top()<<" Has Been popped"<<endl;
    s1.display();
}
