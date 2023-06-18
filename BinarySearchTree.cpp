#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int value;
    node *Left;
    node *Right;
};

class BinarySearchTree{
public:
    node *root;
    BinarySearchTree()
    {
        root = NULL;
    }
    node* CreateNode(int data)
    {
        node *newnode = new node;
        newnode->value = data;
        newnode->Left = NULL;
        newnode->Right = NULL;
        return newnode;
    }
    void Insert(int data)
    {
        node *newnode = CreateNode(data);
        if(root == NULL)
        {
            root = newnode;
            return;
        }
        node *cur = root;
        node *prv = NULL;
        while (cur != NULL)
        {
            if(newnode->value > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else{
                prv = cur;
                cur = cur->Left;
            }
        }
        if(newnode->value > prv->value)
        {
            prv->Right = newnode;
        }
        else{
            prv->Left = newnode;
        }
    }
    void BFS()
    {
        //PRINTS LEVEL WISE VALUES
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            int l =-1, r= -1;
            node *a = q.front();
            q.pop();
            if(a->Left != NULL)
            {
                q.push(a->Left);
                l = a->Left->value;
            }
            if(a->Right != NULL)
            {
                q.push(a->Right);
                r = a->Right->value;
            }
            cout<<"Node value = "<<a->value<<" , Left child value = "<<l<<" , Right child value = "<<r<<'\n';
        }
        cout<<'\n';
    }
    bool Search(int data)
    {
        node *cur = root;
        while(cur != NULL)
        {
            if(data > cur->value)
            {
                cur = cur->Right;
            }
            else if(data < cur->value)
            {
                cur = cur->Left;
            }
            else
                return true;
        }
        return false;
    }
    void Delete(int data)
    {
        node *prv = NULL;
        node *cur = root;
        while (cur != NULL)
        {
            if(data > cur->value)
            {
                prv = cur;
                cur = cur->Right;
            }
            else if(data < cur->value)
            {
                prv = cur;
                cur = cur->Left;
            }
            else{
                break;
            }
        }
        if(cur == NULL){
            cout<<"Value isn't present in BST\n";
            return;
        }
        else{
            //Case :: 1 When it has no child
            if(cur->Left == NULL && cur->Right == NULL)
            {
                if(prv->Left != NULL && prv->Left->value == cur->value){
                    prv->Left = NULL;
                }
                else{
                    prv->Right = NULL;
                }
                delete cur;
                return;
            }
            //Case :: 2 if one child only
            else if(cur->Left != NULL && cur->Right == NULL)
            {
                if(prv->Left != NULL && prv->Left->value == cur->value){
                    prv->Left = cur->Left;
                }
                else{
                    prv->Right = cur->Left;
                }
                delete cur;
                return;
            }
            else if(cur->Right != NULL && cur->Left == NULL)
            {
                if(prv->Left != NULL && prv->Left->value == cur->value){
                    prv->Left = cur->Right;
                }
                else{
                    prv->Right = cur->Right;
                }
                delete cur;
                return;
            }
            //Case :: 3 when node has 2 child
            node *tmp = cur->Right;
            while(tmp->Left != NULL){
                tmp = tmp->Left;
            }
            int Saved = tmp->value;
            Delete(Saved);
            cur->value = Saved;
        }
    }
};

int main()
{
    BinarySearchTree bst;
    bst.Insert(6);
    bst.Insert(4);
    bst.Insert(3);
    bst.Insert(5);
    bst.Insert(7);
    bst.Insert(8);
    bst.Delete(6);
    bst.Delete(4);
    bst.BFS();

    return 0;
}