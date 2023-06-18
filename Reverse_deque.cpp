#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *nxt;
    node *prv;
};

class Deque{
public:
    node *head;
    node *tail;
    int sz, rev;
    Deque()
    {
        rev = 0;
        sz = 0;
        head = NULL;
        tail = NULL;
    }
    node * Createnode(int val)
    {
        node *newnode = new node;
        newnode->data = val;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }
    void InsertAtHead(int val)
    {
        sz++;
        node *newnode = Createnode(val);
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
    void InsertAtTail(int val)
    {
        sz++;
        node *newnode = Createnode(val);
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
    void push_front(int val)
    {
        if(rev == 0)
        {
            InsertAtHead(val);
        }
        else
        {
            InsertAtTail(val);
        }
    }
    void push_back(int val)
    {
        if(rev == 0)
        {
            InsertAtTail(val);
        }
        else
        {
            InsertAtHead(val);
        }
    }
    void DeleteAtHead()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        sz--;
        node *a = head;
        head = a->nxt;
        delete a;
        return;
    }
    void DeleteAtTail()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return;
        }
        sz--;
        node *a = tail;
        tail = a->prv;
        delete a;
        return;
    }
    void pop_front()
    {
        if(rev == 0)
        {
            DeleteAtHead();
        }
        else
        {
            DeleteAtTail();
        }
    }
    void pop_back()
    {
        if(rev == 0)
        {
            DeleteAtTail();
        }
        else
        {
            DeleteAtHead();
        }
    }
    int front()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        if(rev == 0)
        {
            return head->data;
        }
        else
        {
            return tail->data;
        }
    }
    int back()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        if(rev == 0)
        {
            return tail->data;
        }
        else
        {
            return head->data;
        }
    }
    void travers()
    {
        if(rev == 0)
        {
            node *a = head;
            while(a != NULL)
            {
                cout<<a->data<<" ";
                a = a->nxt;
            }
            cout<<'\n';
        }
        else
        {
            node *a = tail;
            while(a != NULL)
            {
                cout<<a->data<<" ";
                a = a->prv;
            }
            cout<<'\n';
        }
    }
    void Reaverse_Deque()
    {
        if(rev == 0)
            rev = 1;
        else
            rev = 0;
    }
    int getsize()
    {
        return sz;
    }
};

int main()
{
    Deque d;
    d.push_back(10);
    d.push_back(15);
    d.push_back(20);
    d.push_front(25);
    d.push_front(30);
    d.push_front(35);
    cout<<d.getsize()<<"\n";
    d.travers();
    d.Reaverse_Deque();
    d.travers();
    // d.pop_back();
    // cout<<d.back()<<'\n';
    // d.pop_back();
    // cout<<d.back()<<'\n';
     d.pop_front();
     cout<<d.front()<<'\n';
     d.pop_front();
     cout<<d.front()<<'\n';
     cout<<d.getsize()<<"\n";
    return 0;
}