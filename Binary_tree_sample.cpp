#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int id,value;
    node *Left;
    node *Right;
    node *Parent;
};
class BinaryTree{
public:
    node *root;
    BinaryTree()
    {
        root = NULL;
    }
    node* CreateNode(int id, int value)
    {
        node *newnode = new node;
        newnode->id = id;
        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right = NULL;
        newnode->Parent = NULL;
        return newnode;
    }
    void Insertion(int id, int value)
    {
        node *newnode = CreateNode(id,value);
        if(root == NULL)
        {
            root = newnode;
            return;
        }
        queue<node*> q;
        node *a = root;
        q.push(a);
        while(!q.empty())
        {
            node *b = q.front();
            q.pop();
            if(b->Left != NULL)
            {
                q.push(b->Left);
            }
            else
            {
                b->Left = newnode;
                newnode->Parent = b;
                return;
            }
            if(b->Right != NULL)
            {
                q.push(b->Right);
            }
            else{
                b->Right = newnode;
                newnode->Parent = b;
                return;
            }
        }
    }
    void Search(node *a, int value)
    {
        if(a == NULL)
        {
            return;
        }
        if(a->value == value)
        {
            cout<<a->id<<" ";
        }
        Search(a->Left, value);
        Search(a->Right, value);
    }
    void BFS()
    {
        //PRINTS LEVEL WISE IDS
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            int l =-1, r= -1, v =0;
            node *a = q.front();
            q.pop();
            v = a->value;
            if(a->Left != NULL)
            {
                q.push(a->Left);
                l = a->Left->id;
            }
            if(a->Right != NULL)
            {
                q.push(a->Right);
                r = a->Right->id;
            }
            cout<<"Node = "<<a->id<<" ,Value = "<<v<<" , Left child = "<<l<<" , Right child = "<<r<<'\n';
        }
        cout<<'\n';
    }
    void DFS(node *a)
    {
        if(a == NULL)
        {
            return;
        }
        cout<<a->id<<" ";
        DFS(a->Left);
        DFS(a->Right);
        return;
    }
    void Inorder(node *a)
    {
        if(a == NULL)
        {
            return;
        }
        Inorder(a->Left);
        cout<<a->id<<" ";
        Inorder(a->Right);
        return;
    }
    void Preorder(node *a)
    {
        if(a == NULL)
        {
            return;
        }
        cout<<a->id<<" ";
        Preorder(a->Left);
        Preorder(a->Right);
        return;
    }
    void Postorder(node *a)
    {
        if(a == NULL)
        {
            return;
        }
        Postorder(a->Left);
        Postorder(a->Right);
        cout<<a->id<<" ";
        return;
    }
};
int main()
{
    BinaryTree bt;
    bt.Insertion(0,5);
    bt.Insertion(1,4);
    bt.Insertion(2,9);
    bt.Insertion(3,5);
    bt.Insertion(4,1);
    bt.Insertion(5,7);
    //bt.Search(bt.root, 9);
    //bt.BFS();
    bt.Postorder(bt.root);

    //bt.PrintTree(bt.root);
    return 0;
}