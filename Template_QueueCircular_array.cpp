#include <bits/stdc++.h>
using namespace std;

template <class T>
class Queue
{
public:
    T *a;
    int l, r, sz, cap;
    Queue()
    {
        cap = 1;
        a = new T[1];
        l = 0;
        r = -1;
        sz = 0;
    }
    void RemoveCircular()
    {
        if(l > r)
        {
            T *temp = new T[cap];
            int idx = 0;
            for(int k=l; k<cap; k++)
            {
                temp[idx] = a[k];
                idx++;
            }
            for(int k=0; k<=r; k++)
            {
                temp[idx] = a[k];
                idx++;
            }
            swap(a,temp);
            delete [] temp;
            l = 0;
            r = cap - 1;
        }
        return;
    }
    void IncreaseSize()
    {
        RemoveCircular();
        T *temp = new T[cap*2];
        for(int k=0; k<cap; k++)
            temp[k] = a[k];
        swap(temp,a);
        delete [] temp;
        cap*=2;
        return;
    }
    void enqueue(T val)
    {
        if(sz == cap)
        {
            IncreaseSize();
        }
        r++;
        if(r == cap)
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
        if(l == cap)
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