#include<bits/stdc++.h>
using namespace std;

template <class T>
class node{
public:
    int data;
    node *nxt;
};
template <class T>
class Queue{
public:
    node<T> *head;
    node<T> *tail;
    int sz;
    Queue()
    {
        sz = 0;
        head = NULL;
        tail = NULL;
    }
    node<T>* Createnode(T val)
    {
        node<T> * newnode = new node<T>;
        newnode->data = val;
        newnode->nxt = NULL;
        return newnode;
    }
    void enqueue(T val)
    {
        sz++;
        node<T> *newnode = Createnode(val);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->nxt = newnode;
        tail = newnode;
        return;
    }
    void dequeue()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        sz--;
        node<T> *a = head;
        head = a->nxt;
        delete a;
    }
    T front()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            T a;
            return a;
        }
        return head->data;
    }
    int Size()
    {
        return sz;
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(15);
    cout<<q.Size()<<'\n';
    cout<<q.front()<<'\n';
    q.dequeue();
    cout<<q.front()<<'\n';
    q.dequeue();
    cout<<q.front()<<'\n';
    q.dequeue();
    cout<<q.Size()<<'\n';

    Queue<char> q1;
    q1.enqueue('a');
    q1.enqueue('b');
    q1.enqueue('c');
    cout<<q1.Size()<<'\n';
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.Size()<<'\n';
   
    return 0;
}