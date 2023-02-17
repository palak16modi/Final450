// reverse first k elements of a queue

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
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

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    queue<int>t;
        while(k>0) {
            t.push(q.front());
            q.pop();
            k--;
        }
        q = rev(q);
        while(!t.empty()){
            q.push(t.front());
            t.pop();
        }
        
        q = rev(q);
        return q;
    
    
}
