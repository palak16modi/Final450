// Find the minimum number of removals required such that max-min<=k
// array solution in array folder with O(nlogn)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve( int arr[], int k, int i, int j){
	if(i >= j) return 0;
	if(arr[j]-arr[i] <= k) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = 1 + min(solve(arr, k, i+1, j), solve(arr, k, i, j-1));
}

int minRemoval(int arr[], int n, int k) {
    sort(arr, arr+n);
    memset(dp, -1, sizeof(dp));
    return solve(arr, k, 0, n-1);
}

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<minRemoval(arr, n, k);
	return 0;
}
