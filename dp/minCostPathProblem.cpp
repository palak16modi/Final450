// Maximum path sum in matrix

#include <iostream>
#include <vector>
using namespace std;

int maximumPath(int n, vector<vector<int>> arr)
{
    int mx;
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<n; j++){
            if(j-1 < 0) mx = max(arr[i+1][j], arr[i+1][j+1]);
            else if(j+1 > n-1) {
                mx = max(arr[i+1][j], arr[i+1][j-1]);
            }
            else{
                mx = max(arr[i+1][j], max(arr[i+1][j-1], arr[i+1][j+1]));
            }
            arr[i][j] += mx;
        }
    }
    int ans = 0;
    for(int j=0; j<n; j++){
        ans = max(ans, arr[0][j]);
    }
    return ans;
}

int main(int argc, char** argv) {
	vector<vector<int>> arr;
	int n,t;
	cin>>n;
	for(int i=0; i<n; i++){
		vector<int> v;
		for(int j=0; j<n; j++){
			cin>>t;
			v.push_back(t);
		}
		arr.push_back(v);
	}
	cout<<maximumPath(n, arr);
	return 0;
}
