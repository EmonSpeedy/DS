#include <bits/stdc++.h>
using namespace std;
template <class T>
class node{
public:
    T data;
    node *nxt;
    node *prv;
};
template <class T>
class Deque{
public:
    node<T> *head;
    node<T> *tail;
    int sz;
    Deque()
    {
        sz = 0;
        head = NULL;
        tail = NULL;
    }
    node<T> * Createnode(int val)
    {
        node<T> *newnode = new node<T>;
        newnode->data = val;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }
    void push_front(T val)
    {
        sz++;
        node<T> *newnode = Createnode(val);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        head->prv = newnode;
        newnode->nxt = head;
        head = newnode;
        return;
    }
    void push_back(T val)
    {
        sz++;
        node<T> *newnode = Createnode(val);
        if(tail == NULL)
        {
            tail = newnode;
            head = newnode;
            return;
        }
        tail->nxt = newnode;
        newnode->prv = tail;
        tail = newnode;
        return;
    }
    void pop_front()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        sz--;
        node<T> *a = head;
        head = a->nxt;
        delete a;
        return;
    }
    void pop_back()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        sz--;
        node<T> *a = tail;
        tail = a->prv;
        delete a;
        return;
    }
    T front()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            T a;
            return a;
        }
        return head->data;
    }
    T back()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            T a;
            return a;
        }
        return tail->data;
    }
    void travers()
    {
        node<T> *a = head;
        while(a != NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<'\n';
    }
    T max()
    {
        T mx = head->data;
        node<T> *a = head;
        while(a != NULL)
        {
            if(a->data > mx)
            {
                mx = a->data;
            }
            a = a->nxt;
        }
        return mx;
    }
    T min()
    {
        T mn = head->data;
        node<T> *a = head;
        while(a != NULL)
        {
            if(a->data < mn)
            {
                mn = a->data;
            }
            a = a->nxt;
        }
        return mn;
    }
    int getsize()
    {
        return sz;
    }
};

int main()
{
    Deque<int> d;
    d.push_back(10);
    d.push_back(15);
    d.push_back(20);
    d.push_front(50);
    d.push_front(30);
    d.push_front(35);
    cout<<d.getsize()<<"\n";
    d.travers();
    cout<<d.max()<<'\n';
    cout<<d.min()<<'\n';
   // d.pop_back();
    //cout<<d.back()<<'\n';
   // d.pop_back();
   // cout<<d.back()<<'\n';
    // d.pop_front();
    // cout<<d.front()<<'\n';
    // d.pop_front();
    // cout<<d.front()<<'\n';
    // cout<<d.getsize()<<"\n";
    return 0;
}