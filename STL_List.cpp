#include<bits/stdc++.h>
using namespace std;
//Author :: MD SH EMON :)
void Print(list<int> l)
{
    auto a = l.begin();
    while (a != l.end())
    {
        cout<< *a <<" ";
        a++;
    }
    cout<<"\n";
    return;
}
void Insert(list<int>&l, int index, int val)
{
    auto it = l.begin();
    advance(it, index);
    l.insert(it, val);
    return;
}
void Delete(list<int>&l, int index)
{
    auto it = l.begin();
    advance(it, index);
    l.erase(it);
    return;
}

int main()
{
    list<int> l;
    //push front O(1)
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    //Print O(n)
   // Print(l);

    l.push_back(40);
    l.push_back(50);
    l.push_back(60);
    // Print(l);

    //Insert at any index
    Insert(l, 2, 100);
    Print(l);
    //Deletes any index
    Delete(l, 3);
    Print(l);
    return 0;
}