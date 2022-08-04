// finding median element in a sorted matrix

#include <bits/stdc++.h>
using namespace std;

int bs(vector<vector<int>> mat, int low, int high, int k){
	int mid = low+(high-low)/2;
	int c=0;
	if(low<high){
		for(auto i: mat){
			auto p = upper_bound(i.begin(), i.end(), mid);
			if(p==i.end()){
				c=c+mat.size();
			}
			else{
				c=c+ (p-i.begin());
			}
		}
		if(c<k) {
			return bs(mat, mid+1, high, k);
		}
		else {
			return bs(mat, low, mid, k);
		}
	}
	return low;
}

int median(vector<vector<int>> mat, int n, int k){
	int low = mat[0][0];
	int high = mat[n-1][n-1];
	return bs(mat, low, high, k);
}


int main(int argc, char** argv) {
	int n;
	cin>>n;
	vector<vector<int>> mat;
	for(int i=0; i<n; i++){
		vector<int> v;
		for(int j=0; j<n; j++){
			int t;
			cin>>t;
			v.push_back(t);
		}
		mat.push_back(v);
	}
	int k = (n*n/2)+1;
	cout<<median(mat, n, k);
	return 0;
}
