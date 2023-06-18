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
    Stack<int> st;
    st.Insert(10);
    st.Insert(40);
    st.Insert(30);
    cout<<st.getSize()<<"\n";
    cout<<st.Top_view()<<'\n';
    st.Delete();
    cout<<st.Top_view()<<'\n';
    st.Delete();
    cout<<st.Top_view()<<'\n';
    cout<<st.Top_view()<<'\n';
    cout<<st.getSize()<<"\n";

    Stack<char> st1;
    st1.Insert('a');
    st1.Insert('g');
    st1.Insert('f');
    cout<<st1.getSize()<<"\n";
    cout<<st1.Top_view()<<'\n';
    st1.Delete();
    cout<<st1.Top_view()<<'\n';
    st1.Delete();
    cout<<st1.Top_view()<<'\n';
    st1.Delete();
    cout<<st1.Top_view()<<'\n';
    return 0;
}