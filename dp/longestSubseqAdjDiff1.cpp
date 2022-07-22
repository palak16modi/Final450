// Longest subsequence such that difference between adjacent is one

#include <iostream>
using namespace std;

int longestSubsequence(int n, int a[])
{
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++){
        int mx = 0;
        for(int j=0; j<i; j++){
            if(abs(a[i]-a[j]) == 1) {
               mx = max(mx, dp[j]+1);
            }
        }
        if(mx==0) mx=1;
        dp[i] = mx;
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<longestSubsequence(n,arr);
	
	return 0;
}
