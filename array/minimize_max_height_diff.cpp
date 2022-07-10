// minimize the maximum difference in heights

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n;i++) cin>>arr[i];
	sort(arr, arr+n);
	int mx,mi;
	int result = arr[n-1]-arr[0];
	for(int i=1;i<n;i++){
		mx = max(arr[n-1]-k, arr[i-1]+k);
		if(arr[i]-k <0) continue;
		mi = min(arr[0]+k, arr[i]-k);
		result = min(result,mx-mi);
	}
	cout<<result;
	return 0;
}
