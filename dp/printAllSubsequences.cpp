// printing all the subsequences

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubsequesnces(int arr[], int n){
	vector<vector<int>> ans;
	vector<int> v;
	v.push_back(arr[0]);
	ans.push_back(v);
	for(int i=1; i<n; i++){
		int s = ans.size();
		v[0] = arr[i];
		ans.push_back(v);
		vector<int> t;
		for(int      j=0; j<s; j++){
			t = ans[j];
			t.push_back(arr[i]);
			ans.push_back(t);
		}
	}
	for(int i=0; i<ans.size(); i++){
		cout<<"{";
		for(int j=0; j<ans[i].size(); j++) cout<<ans[i][j];
		cout<<"} ";
	}
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	printSubsequesnces(arr, n);
	return 0;
}
