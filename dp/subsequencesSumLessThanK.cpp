// finding number of subsequences whose product is less than k

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int subsequencesSumLessThanK(int arr[], int n, int k){
	vector<int> v;
	if(arr[0] >= k) return 0;
	v.push_back(arr[0]);
	for(int i=1; i<n; i++){
		int s = v.size();
		if(arr[i] < k) {
			v.push_back(arr[i]);
			for(int j=0; j<s; j++){
				int pdt = v[j]*arr[i];
				if(pdt < k) v.push_back(pdt); 
			}
		}
	}
	return v.size();
}

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<subsequencesSumLessThanK(arr, n, k)<<endl;
	return 0;
}
