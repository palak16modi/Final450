// Find the minimum number of removals required such that twice of minimum element in the array is greater than or equal to the maximum 
// in the array.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minRemoval(int arr[], int n) {
	    // code here
	    sort(arr, arr+n);
	    int ans = n;
	    for(int i=0;i<n;i++){
	        int index = upper_bound(arr, arr+n, 2*arr[i])-arr;
	        if(index!=-1) ans = min(ans, n+i-index);
	    }
	    return ans;
	}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<minRemoval(arr, n);
	return 0;
}
