// Maximum subsequence sum such that no three are consecutive

#include <iostream>
using namespace std;

int maxSum(int arr[], int n){
	int dp[n];
	dp[0] = arr[0];
	dp[1] = arr[0]+arr[1];
	dp[2] = max(arr[1], max(arr[0]+arr[2], arr[1]+arr[2]));
	for(int i=3; i<n; i++){
		int sum1 = dp[i-1];
		int sum2 = arr[i]+dp[i-2];
		int sum3 = arr[i]+arr[i-1]+dp[i-3]; 
		dp[i] = max(sum1, max(sum2,sum3));
	}
	return dp[n-1];
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<maxSum(arr, n);
	return 0;
}
