#include<bits/stdc++.h>
using namespace std;

const int max_sz = 10;
class Queue{
public:
    int a[max_sz];
    int l, r;
    Queue()
    {
        l = 0;
        r = -1;
    }
    void enqueue(int val)
    {
        if(r+1 >= max_sz)
        {
            cout<<"Queue is full\n";
            return;
        }
        r++;
        a[r] = val;
    }
    void dequeue()
    {
        if(l > r)
        {
            cout<<"Queue is empty\n";
            return;
        }
        l++;
    }
    int front()
    {
        if(l > r)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return a[l];
    }
    int Size()
    {
        return r-l+1;
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
   
    
