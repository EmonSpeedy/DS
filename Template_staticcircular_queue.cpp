#include <bits/stdc++.h>
using namespace std;
const int max_sz = 4;

template <class T>
class Queue
{
public:
    T a[max_sz];
    int l, r, sz;
    Queue()
    {
        l = 0;
        r = -1;
        sz = 0;
    }
    void enqueue(T val)
    {
        if(sz == max_sz)
        {
            cout<<"Queue is full\n";
            return;
        }
        r++;
        if(r == max_sz)
        {
            r = 0;
        }
        sz++;
        a[r] = val;
        return;
    }
    void dequeue()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        l++;
        if(l == max_sz)
        {
            l = 0;
        }
        sz--;
        return;
    }
    T front()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            assert(false);
        }
        return a[l];
    }
    int getsize()
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
    cout<<q.getsize()<<'\n';
    cout<<q.front()<<'\n';
    q.dequeue();
    cout<<q.front()<<'\n';
    q.dequeue();
    cout<<q.front()<<'\n';
    q.dequeue();
    cout<<q.getsize()<<'\n';
    cout<<endl;

    Queue<char> q1;
    q1.enqueue('a');
    q1.enqueue('b');
    q1.enqueue('c');
    cout<<q1.getsize()<<'\n';
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.front()<<'\n';
    q1.dequeue();
    cout<<q1.getsize()<<'\n';
    return 0;
}