// flood fill

#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& image, int sr, int sc, int color, int mycolor, vector<vector<int>>& visited, int n, int m){
	if(sr<n && sr>=0 && sc>=0 && sc<m){
		int myclr = image[sr][sc];
		if(myclr == mycolor && visited[sr][sc]==0){
			visited[sr][sc] = 1;
			// up
			solve(image, sr-1, sc, color, myclr, visited, n, m);
			// right
			solve(image, sr, sc+1, color, myclr, visited, n, m);
			//bottom
			solve(image, sr+1, sc, color, myclr, visited, n, m);
			//left
			solve(image, sr, sc-1, color, myclr, visited, n, m);
			// change color
			image[sr][sc] = color;
			return;
		}
		else return;
	}
	else return;
}

 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
 	int n = image.size();
 	int m = image[0].size();
 	cout<<n<<m<<endl;
 	vector<vector<int>> visited;
 	for(int i=0; i<n; i++){
 		vector<int> t;
 		for(int j=0; j<m; j++){
 			t.push_back(0);
		 }
		 visited.push_back(t);
	 }
 	int mycolor = image[sr][sc];
    solve(image, sr, sc, color, mycolor, visited, n, m);
    return image;
}

int main(int argc, char** argv) {
	int n,m,x;
	cin>>n>>m;
	vector<vector<int>> image;
	for(int i=0; i<n; i++){
		vector<int> t;
		for(int j=0; j<m; j++){
			cin>>x;
			t.push_back(x);
		}
		image.push_back(t);
	}
	int sr,sc,color;
	cin>>sr>>sc>>color;
	image = floodFill(image, sr, sc, color);
	for(auto i : image){
		for(auto j : i) cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}
