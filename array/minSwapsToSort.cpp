// Minimum number of swaps required to sort an array

#include <bits/stdc++.h>
using namespace std;

void makeList(map<int, vector<int>> &adj, unordered_map<int,int> u){
    for(auto i: u){
        adj[i.first].push_back(i.second);
    }
}

int solve(unordered_map<int,int> u, vector<int> t){
    map<int, vector<int>> adj;
    makeList(adj, u);
    unordered_map<int,bool> visited;
    int swaps=0;
    stack<int> s;
    for(auto i : t){
        visited[i]=0;
        s.push(i);
    }
    while(!s.empty()){
        int top = s.top();
        visited[top]=1;
        s.pop();
        for(auto i : adj[top]){
            if(visited[i]==0){
                s.push(i);
                swaps++;
            }
        }
    }
    return swaps;
}

int minSwaps(vector<int>&nums)
{
    vector<int> t;
    t=nums;
    unordered_map<int,int> u;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        u[nums[i]]=t[i];
    }
    return solve(u,t);
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin>>v[i];
	cout<<minSwaps(v);
	return 0;
}
