#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int a[n];
	int mx=arr[0];
	for(int i=0; i<n; i++) a[i]=max(mx,arr[i]);
	mx=arr[n-1];
	int sum=0;
	for(int i=n-1; i>=0; i--){
		mx = max(mx, arr[i]);
		sum = sum + min(mx,a[i])-arr[i];
	}
	cout<<sum;
	return 0;
}
