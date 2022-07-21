// check if an array can be partitioned into two parts with equal sum

#include <iostream>
using namespace std;

int sum(int arr[], int n){
    int sum = arr[0];
    for(int i=1; i<n; i++){
        sum = sum+arr[i];
    }
    return sum;
}

int equalPartition(int n, int arr[])
{
    int m = sum(arr, n);
    if(m%2==1) return 0;
    m=m/2;
    bool dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(j==0) dp[i][j]=1;
            else if(i==0) dp[i][j]=0;
            else{
                if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
                }
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<equalPartition(n,arr);
	return 0;
}
