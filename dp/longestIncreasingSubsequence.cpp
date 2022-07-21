#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
   // your code here
   int dp[n+1];
   dp[0] = INT_MIN;
   for(int i=1; i<=n; i++) dp[i]=INT_MAX;
   for(int i=0; i<n; i++){
       int index = upper_bound(dp, dp+n+1, a[i]) - dp;
       if(a[i]>dp[index-1] && a[i]<dp[index]) dp[index] = a[i];
   }
   for(int i=n; i>=0; i--){
       if(dp[i] != INT_MAX){
           return i;
       }
   }
   return 1;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<longestSubsequence(n, arr);
	return 0;
}
