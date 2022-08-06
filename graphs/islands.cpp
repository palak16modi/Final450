#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &visited, int n, int m){
        
    if (i<0 || j<0 || i>=n || j>=m){
       return;
   }
	if(visited[i][j]!=1 && grid[i][j]=='1'){
	
        visited[i][j]=1;
        
        //left
        dfs(grid, i, j-1, visited, n, m);
        
        //right
        dfs(grid, i, j+1, visited, n, m);
        
        //up
        dfs(grid, i+1, j, visited, n, m);
        
        //down
        dfs(grid, i-1, j, visited, n, m);
        
        //upper left
        dfs(grid, i+1, j-1, visited, n, m);
        
        // upper right
        dfs(grid, i+1, j+1, visited, n, m);
        
        //lower left
        dfs(grid, i-1, j-1, visited, n, m);
        
        //lower right
        dfs(grid, i-1, j+1, visited, n, m);
	}
}

int numIslands(vector<vector<char>>& grid) {
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> visited;
    for(int i=0; i<n; i++){
    	vector<int> v;
        for(int j=0; j<m; j++){
            v.push_back(0);
        }
        visited.push_back(v);
    }
    
    int c=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='1' && visited[i][j]==0){
                c++;
                dfs(grid, i, j, visited, n, m);
            }
        }
	}
    return c;
}


int main(int argc, char** argv) {
	vector<vector<char>> grid = {{'0','1'},{'1','0'},{'1','1'},{'1','0'}};
	cout<<numIslands(grid);
	return 0;
}
