#include<bits/stdc++.h>
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
    st.Insert(1);
    st.Insert(5);
    st.Insert(2);
    st.Insert(3);
    st.Insert(7);

    Stack<int> tmp;
    while(st.getSize())
    {
        int t = st.Top_view();
        st.Delete();
        if(tmp.getSize() == 0)
        {
            tmp.Insert(t);
        }
        else
        {
            while(tmp.getSize() != 0)
            {
                if(tmp.Top_view() < t)
                {
                    break;
                }
                else
                {
                    int b = tmp.Top_view();
                    tmp.Delete();
                    st.Insert(b);   
                }
            }
            tmp.Insert(t);
        }
    }
    swap(st,tmp);
    while(st.getSize())
    {
        cout<<st.Top_view()<<" ";
        st.Delete();
    }

    return 0;
}
