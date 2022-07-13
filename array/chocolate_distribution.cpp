#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int i=0,j=k-1;
	sort(arr, arr+n);
	int ans = INT_MAX;
	for(int i=0; j<n; i++){
		ans = min(ans, arr[j]-arr[i]);
		j++;
	}
	cout<<ans;
	return 0;
}
