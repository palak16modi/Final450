// rotate a matrix by 90 deg

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(matrix[j][i], matrix[n-j-1][i]);
        }
    }
}

int main(int argc, char** argv) {
	vector<vector<int>> v = {{1,2,3},{4,5,6},{7,8,9}};
	rotate(v);
	for(auto i : v){
		for(auto j : i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
