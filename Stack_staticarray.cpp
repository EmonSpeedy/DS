//Author :: MDSH EMON
#include <bits/stdc++.h>
using namespace std;
const int Max_sz = 10;
template<class T>
class Stack{
public:
    T ar[Max_sz];
    int sz;
    Stack()
    {
        sz = 0;
    }
    void Insert(T val)
    {
        if(sz == Max_sz)
        {
            cout<<"Stack is full\n";
            return;
        }
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
            assert(false);
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
    st.Delete();

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