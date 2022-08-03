// maximum sum of a rectangle in histogram

#include <bits/stdc++.h>
using namespace std;

long long getMaxArea(long long arr[], int n)
{
    // Your code here
    vector<long long> next(n);
    vector<long long> prev(n);
    
    stack<int> stk;
    stk.push(n);
    for(int i=n-1; i>=0; i--){
        if(stk.top() == n) next[i] = n;
        else if(arr[stk.top()] < arr[i]) next[i]=stk.top();
        else if(arr[stk.top()] >= arr[i]){
            while(stk.top() != n && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            next[i] = (stk.top());
        }
        stk.push(i);
    }
    
    while(!stk.empty()){
        stk.pop();
    }
    stk.push(-1);
    for(int i=0; i<n; i++){
        if(stk.top() == -1) prev[i]=-1;
        else if(arr[stk.top()] < arr[i]) prev[i]=stk.top();
        else if(arr[stk.top()] >= arr[i]){
            while(stk.top() != -1 && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            prev[i] = stk.top();
        }
        stk.push(i);
    }
    
    long long ans=0;
    for(int i=0; i<n; i++){
        long long t = (next[i]-prev[i]-1) * arr[i];
        if(t>ans){
            ans = t;
        }
    }
    return ans;
}


int main(int argc, char** argv) {
	int n;
	cin>>n;
	long long arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<getMaxArea(arr,n);
	return 0;
}
