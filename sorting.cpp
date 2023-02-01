#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class Student
{
    char * name;
    int id;
public:
    Student()
    {
        name = NULL;
    }
    Student(char * p,int i)
    {
        name = new char[strlen(p)+1];
        strcpy(name,p);
        id = i;
    }
    void set_info(char * p,int i)
    {
        name = new char[strlen(p)+1];
        strcpy(name,p);
        id = i;
    }
    int get_ID()
    {
        return id;
    }
    void display()
    {
        printf("Student Name:%s\n",name);
        printf("Student Id:%d\n",id);
    }
    ~Student()
    {
        delete [] name;
    }
};
void insertion_sort(Student arr[],int size)
{
    int key,j;
    for(int i=1;i<size;i++)
    {
        key=arr[i].get_ID();
        Student temp = arr[i];
        j=i-1;
        while(j>=0&&arr[j].get_ID()>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    Student s[4];
    for(int i=0;i<4;i++)
    {
        string s1;
        cin>>s1;
        int x;
        cin>>x;
        s[i].set_info(&s1[0],x);
    }
    /*for(int i=0;i<4;i++)
    {
        s[i].display();
    }*/
    insertion_sort(s,4);
    /*bool swapped = true;
    while(swapped == true)
    {
        swapped = false;
        for(int i=0;i<3;i++)
        {
            if(s[i].get_ID()>s[i+1].get_ID())
            {
                swap(s[i],s[i+1]);
                swapped = true;
            }
        }
    }*/
    for(int i=0;i<4;i++)
    {
        s[i].display();
    }
}
