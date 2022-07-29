// rat and maze problem

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> visited, vector<vector<int>> arr, int &n){
    if( (newx>=0 && newx<n) && (newy>=0 && newy<n) && 
    (arr[newx][newy]==1) && (visited[newx][newy]==0)){
        return true;
    }
    else return false;
}

void solve(int x, int y, vector<vector<bool>> &visited, string path, vector<string> &ans, 
vector<vector<int>> &m, int n){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    // Down
    if(isSafe(x+1, y, visited, m, n)){
        visited[x][y] = 1;
        solve(x+1, y, visited, path+'D', ans, m, n);
        visited[x][y] = 0;
    }
    
    // Left
    if(isSafe(x, y-1, visited, m, n)){
        visited[x][y] = 1;
        solve(x, y-1, visited, path+'L', ans, m, n);
        visited[x][y] = 0;
    }
    
    // Right
    if(isSafe(x, y+1, visited, m, n)){
        visited[x][y] = 1;
        solve(x, y+1, visited, path+'R', ans, m, n);
        visited[x][y] = 0;
    }
    
    // Up
    if(isSafe(x-1, y, visited, m, n)){
        visited[x][y] = 1;
        solve(x-1, y, visited, path+'U', ans, m, n);
        visited[x][y] = 0;
    }
    
    visited[x][y] = 0;
    
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    // Your code goes here
    vector<string> ans;
    if(m[0][0] == 0) return ans;
    vector<vector<bool>> visited (n, vector<bool>(n,0));
    string path = "";
    solve(0, 0, visited, path, ans, m, n);
    return ans;
}

int main(int argc, char** argv) {
	int n,t;
	cin>>n;
	vector<vector<int>> m;
	for(int i=0; i<n; i++){
		vector<int> s;
		for(int j=0; j<n; j++){
			cin>>t;
			s.push_back(t);
		}
		m.push_back(s);
	}
	vector<string> v;
	v = findPath(m,n);
	for(auto i: v) cout<<i<<" ";
	return 0;
}
