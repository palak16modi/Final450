// Find the minimum number of removals required such that max-min<=k
// dp solution in dp folder

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minRemoval(int arr[], int n, int k) {
	    // code here
	    sort(arr, arr+n);
	    int ans = n;
	    for(int i=0;i<n;i++){
	        int index = lower_bound(arr, arr+n, arr[i]+k)-arr;
	        if(index!=-1) ans = min(ans, n+i-index);
	    }
	    return ans;
	}

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<minRemoval(arr, n, k);
	return 0;
}
