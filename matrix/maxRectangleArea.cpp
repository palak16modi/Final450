// max area of rectangle

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int getMaxArea(vector<int> arr, int n)
{
    // Your code here
    vector<int> next(n);
    vector<int> prev(n);
    
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
    
    stack<int> st;
    st.push(-1);
    for(int i=0; i<n; i++){
        if(st.top() == -1) prev[i]=-1;
        else if(arr[st.top()] < arr[i]) prev[i]=st.top();
        else if(arr[st.top()] >= arr[i]){
            while(st.top() != -1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            prev[i] = st.top();
        }
        st.push(i);
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        int t = (next[i]-prev[i]-1) * arr[i];
        if(t>ans){
            ans = t;
        }
    }
    return ans;
}


int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    vector<vector<int>> v;
    vector<int> q;
    for(int i=0;i<m;i++) q.push_back(M[0][i]);
    v.push_back(q);
    for(int i=1; i<n; i++){
        vector<int> p;
        for(int j=0; j<m; j++){
            if(M[i][j]!=0) p.push_back(v[i-1][j]+1);
            else p.push_back(0);
        }
        v.push_back(p);
    }

    int ans = 0;
    for(auto i : v){
        int t = getMaxArea(i,m);
        ans = max(ans, t);
    }
    return ans;
}

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	int M[MAX][MAX];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>M[i][j];
		}
	}
	cout<<maxArea(M,n,m);
	return 0;
}
