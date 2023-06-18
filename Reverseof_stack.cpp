#include <bits/stdc++.h>
using namespace std;
//Author :: MD SH EMON :)
template <class T>
class Stack{
public:
    T *ar;
    int ar_cap;
    int sz;
    Stack()
    {
        ar = new T[1];
        ar_cap = 1;
        sz = 0;
    }
    void Increase_cap()
    {
        T *temp = new T[ar_cap*2];
        for(int k=0; k<ar_cap; k++)
        {
            temp[k] = ar[k];
        }
        swap(ar,temp);
        delete []temp;
        ar_cap*=2;
        return;
    }
    void Insert(T val)
    {
        if(sz+1 > ar_cap)
            Increase_cap();
        ar[sz] = val;
        sz++;
        return;
    }
    void Delete()
    {
        if(sz == 0)
        {
            cout<<"Stack is empty\n";
            return;
        }
        sz--;
        return;
    }
    T Top_view()
    {
        if(sz == 0)
        {
            cout<<"Stack is empty\n";
        }
        return ar[sz-1];
    }
    int getSize()
    {
        return sz;
    }
};

int main()
{
    Stack<int> a;
    a.Insert(10);
    a.Insert(20);
    a.Insert(30);
    a.Insert(40);
    a.Insert(50);
    Stack<int> temp;
    while(a.getSize())
    {
        int n = a.Top_view();
        a.Delete();
        temp.Insert(n);
    }
    swap(a,temp);
    while(a.getSize())
    {
        cout<<a.Top_view()<<" ";
        a.Delete();
    }
    cout<<'\n';
    return 0;
}