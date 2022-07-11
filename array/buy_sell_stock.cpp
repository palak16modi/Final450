// buy sell stock only once to get max profit

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int buy=0,sell=0,ind=n;
	for(int i=0; i<(n-1); i++){
		if(arr[i]<arr[i+1]){
			buy = arr[i];
			sell=arr[i+1];
			ind=i+2;
			break;
		}
	}
	for(int i=ind; i<n; i++){
		sell = max(sell, arr[i]);
	}
	cout<<sell-buy;
	return 0;
}
