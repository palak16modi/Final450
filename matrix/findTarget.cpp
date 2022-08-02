#include <bits/stdc++.h>
using namespace std;

bool BS(vector<int> v, int l, int h, int target){
    if(l<=h){
        int mid = (l+h)/2;
        //cout<<v[mid]<<endl;
        if(target==v[mid]) return true;
        if(target<v[mid]) return BS(v,l,mid-1,target);
        else return BS(v,mid+1,h,target);
    }
    else return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int j=matrix[0].size();
    int n=matrix.size();
    int i;
    for(i=0; i<n; i++){
        if(matrix[i][0]<=target && matrix[i][j-1]>=target) break;
    }
    if(i==n) return false;
    //cout<<i<<endl;
    return BS(matrix[i],0,j-1, target);
}

int main(int argc, char** argv) {
	vector<vector<int>> matrix = {{2,3,4},{6,7,8},{9,10,12}};
	int target = 7;
	cout<<searchMatrix(matrix,target)<<endl;
	target = 11;
	cout<<searchMatrix(matrix,target)<<endl;
	return 0;
}
