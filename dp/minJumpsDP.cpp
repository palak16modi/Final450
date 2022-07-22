// The minimum jumps to reach end using dp approach O(n2)

#include <iostream>
using namespace std;

int minJumps(int arr[], int n){
	int dp[n];
	for(int i=0; i<n; i++) dp[i]=INT_MAX;
	dp[0]=0;
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(j+arr[j] >= i){
				dp[i] = min(dp[i], dp[j]+1);
			}
		}
	}
	// for(int i=0; i<n; i++) cout<<dp[i]<<" ";
	return dp[n-1];
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<minJumps(arr, n);
	return 0;
}
