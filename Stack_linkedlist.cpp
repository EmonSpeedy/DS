#include<bits/stdc++.h>
using namespace std;
//Author :: MD SH EMON:)
template<class T>
class node{
public:
    T data;
    node* nxt;
    node* prv;
};

template <class T>
class DoublyLinked_List{
public:
    node<T>* head;
    int sz;
    //Constructor
    DoublyLinked_List()
    {
        head = NULL;
        sz = 0;
    }
    //Creates new nodes
    node<T>* CreateNode(T val)
    {
        node<T>* newnode = new node<T>;
        newnode->data = val;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }
    //Inserts value at head
    void Insertathead(T val)
    {
        node<T>* newnode = CreateNode(val);
        sz++;
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        newnode->nxt = head;
        head->prv = newnode;
        head = newnode;
        return;
    }
    void DeleteAthead()
    {
        if(sz == 0)
        {
            cout<<"Dobly linked list is empty\n";
            return;
        }
        sz--;
        node<T> *a = head;
        head = a->nxt;
        delete a;
        return;
    }
    //Returns the size of D.linked list
    int getSize()
    {
        return sz;
    }

};
template <class T>
class Stack{
public:
    DoublyLinked_List<T> dl;
    int stack_sz;
    Stack()
    {
        stack_sz = 0;
    }
    void Insert(T val)
    {
        dl.Insertathead(val);
        stack_sz++;
    }
    void Delete()
    {
        if(dl.getSize() == 0)
        {
            cout<<"Stack is empty\n";
            return;
        }
        dl.DeleteAthead();
        stack_sz--;
    }
    T Top_view()
    {
        if(dl.getSize() == 0)
        {
            cout<<"Stack is empty\n";
            assert(false);
        }
        return dl.head->data;
    }
    int Getsize()
    {
        return stack_sz;
    }
};

int main()
{
    Stack<int> st;
    st.Insert(10);
    st.Insert(20);
    st.Insert(30);
    st.Insert(25);
    cout<<st.Getsize()<<'\n';
    cout<<st.Top_view()<<'\n';
    st.Delete();
    cout<<st.Top_view()<<'\n';
    st.Delete();
    cout<<st.Top_view()<<'\n';
    cout<<st.Getsize()<<'\n';

    Stack<char> st1;
    st1.Insert('a');
    st1.Insert('g');
    st1.Insert('f');
    cout<<st1.Getsize()<<"\n";
    cout<<st1.Top_view()<<'\n';
    st1.Delete();
    cout<<st1.Top_view()<<'\n';
    st1.Delete();
    cout<<st1.Top_view()<<'\n';
    st1.Delete();
    cout<<st1.Top_view()<<'\n';
    return 0;
}
