// maximum product subarray *use min-max*

#include <iostream>
using namespace std;

int maxProduct(int arr[] int n) {
	    int ma=arr[0],mi=arr[0],ans=arr[0];
	    for(int i=1; i<n ; i++){
	        if(arr[i] < 0) swap(ma,mi);
	        ma = max(arr[i], arr[i]*ma);
	        mi = min(arr[i], arr[i]*mi);
	        ans = max(ma,ans);
	    }
	    return ans;
	}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<maxProduct(arr,n);
	return 0;
}
