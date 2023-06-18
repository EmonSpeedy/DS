#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(5);
    dq.push_back(10);
    dq.push_back(15);
    dq.push_front(20);
    dq.push_front(25);
    dq.push_front(30);

    cout<<dq.size()<<'\n';
    cout<<dq.front()<<'\n';
    dq.pop_front();
    cout<<dq.front()<<'\n';
    dq.pop_front();
    cout<<dq.size()<<'\n';
    cout<<dq.size()<<'\n';

    cout<<dq.back()<<'\n';
    dq.pop_back();
    cout<<dq.back()<<'\n';
    dq.pop_back();

    cout<<dq.size()<<'\n';

    return 0;
}