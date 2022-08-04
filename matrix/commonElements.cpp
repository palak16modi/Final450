// common elements in all the row

#include <bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<vector<int>> mat){
	int n = mat.size();
	int m = mat[0].size();
	unordered_map<int,int> umap;
	for(int i=0; i<m; i++){
		umap[mat[0][i]]++;
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<m; j++){
			if(umap.find(mat[i][j]) == umap.end()) continue;
			else{
				if(umap[mat[i][j]]==i-1) umap[mat[i][j]] = i;
			}
		}
	}
	vector<int> v;
	for(auto i: umap){
		if(i.second == n-1) v.push_back(i.first);
	}
	return v;
}

int main(int argc, char** argv) {
	int n,m,t;
	cin>>n>>m;
	vector<vector<int>> mat;
	for(int i=0; i<n; i++){
		vector<int> v;
		for(int j=0; j<m; j++){
			cin>>t;
			v.push_back(t);
		}
		mat.push_back(v);
	}
	vector<int> ans;
	ans = commonElements(mat);
	for(auto i : ans) cout<<i<<" ";
	return 0;
}
