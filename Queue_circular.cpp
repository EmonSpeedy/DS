#include<bits/stdc++.h>
using namespace std;

class Queue{
public:
    int *a;
    int l, r, sz, cap;
    Queue()
    {
        a = new int[1];
        l = 0;
        r = -1;
        sz = 0;
        cap = 1;
    }
    void remove_circular()
    {
        if(l > r)
        {
            int *temp = new int[cap];
            int idx = 0;
            for(int k=l; k<cap; k++)
            {
                temp[idx] = a[k];
                idx++;
            }
            for(int k=0; k<=r; k++)
            {
                temp[idx] = a[k];
            }
            swap(a,temp);
            delete []temp;
            l = 0;
            r = cap-1;
            delete []temp;
        }
        return;
    }
    void increase_sz()
    {
        remove_circular();
        int *temp = new int[cap*2];
        for(int k=0; k<cap; k++)
            temp[k] = a[k];
        swap(a,temp);
        delete []temp;
        cap*=2;
    }
    void enqueue(int val)
    {
        if(sz == cap)
        {
            increase_sz();
        }
        r++;
        if(r == cap)
        {
            r = 0;
        }
        a[r] = val;
        sz++;
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
    }
    int front()
    {
        if(sz == 0)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return a[l];
    }
    int Size()
    {
        return sz;
    }
};

int main()
{
    Queue q;
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
   
    return 0;
}