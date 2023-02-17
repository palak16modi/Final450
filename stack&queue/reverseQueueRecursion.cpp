#include <bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q);

int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}

queue<int> rev(queue<int> q)
{
    // add code here.
    if(q.empty()) return q;
    int a;
        a = q.front();
        q.pop();
        if(!q.empty()) q = rev(q);
    q.push(a);
    return q;
    
}
