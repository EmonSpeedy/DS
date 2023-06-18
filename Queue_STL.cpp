#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(120);
    q1.push(105);
    cout<<q1.empty()<<'\n';
    cout<<q1.size()<<'\n';
    cout<<q1.front()<<'\n';
    q1.pop();
    cout<<q1.front()<<'\n';
    q1.pop();
    cout<<q1.front()<<'\n';
    q1.pop();
    cout<<q1.front()<<'\n';
    q1.pop();
    cout<<q1.front()<<'\n';
    q1.pop();

    cout<<q1.empty()<<'\n';
    cout<<q1.size();

    return 0;
}