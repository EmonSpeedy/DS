#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* nxt;
    node* prv;
};

class DoublyLinked_List{
public:
    node* head;
    int sz;
    //Constructor
    DoublyLinked_List()
    {
        head = NULL;
        sz = 0;
    }
    //Creates new nodes
    node* CreateNode(int val)
    {
        node* newnode = new node;
        newnode->data = val;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        return newnode;
    }
    //Inserts value at head
    void Insertathead(int val)
    {
        node* newnode = CreateNode(val);
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
    //Inserts value at any index
    void InsertatanyIndex(int val, int idx)
    {
        if(idx == 0)
        {
            Insertathead(val);
            return;
        }
        sz++;
        node* newnode = CreateNode(val);
        node* a =head;
        int ix = 0;
        while(ix != idx-1)
        {
            a = a->nxt;
            ix++;
        }
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node* b = a->nxt;
        b->prv = newnode;
        a->nxt = newnode;
        return;
    }
    //Deletes any index
    void Deleteanyindex(int idx)
    {
        if(head == NULL)
        {
            cout<<"DOubly linked list is already empty\n";
            return;
        }
        sz--;
        int ix = 0;
        node* a = head;
        while(ix != idx)
        {
            a = a->nxt;
            ix++;
        }
        a->prv->nxt = a->nxt;
        a->nxt->prv = a->prv;
        delete a;

    }
    //Printd in reverse order in recursion method
    void Revers_print(node* a)
    {
        if(a == NULL)
        {
            return;
        }
        Revers_print(a->nxt);
        cout<<a->data<<" ";
    }
    //To deliver the head in above function
    void rev()
    {
        Revers_print(head);
        cout<<'\n';
    }
    //It traverse the whole doubly linked list
    void Traverse()
    {
        if(head == NULL)
        {
            cout<<"Doubly Linked List is empty\n";
            return;
        }
        node* a = head;
        while(a != NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<'\n';
    }
    //Returns the size of D.linked list
    int getSize()
    {
        return sz;
    }

};

int main()
{
    DoublyLinked_List dl;
    dl.Insertathead(10);
    dl.Insertathead(20);
    dl.Insertathead(30);
    dl.Insertathead(20);
    dl.Traverse();
    cout<<dl.getSize()<<'\n';
    dl.InsertatanyIndex(100, 2);
    dl.Traverse();
    cout<<dl.getSize()<<'\n';
    dl.rev();
    //dl.Deleteanyindex(1);
    //dl.Traverse();
    //cout<<dl.getSize()<<'\n';
    return 0;
}
