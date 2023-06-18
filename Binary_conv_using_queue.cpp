#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    queue<string> q;
    q.push("1");
    int k = 1;
    while(k != n+1)
    {
        string s = q.front();
        q.pop();
        cout<<"Binary convertion of "<< k <<" is : "<< s <<'\n';
        q.push(s + "0");
        q.push(s + "1");
        k++;
    }

    return 0;
}