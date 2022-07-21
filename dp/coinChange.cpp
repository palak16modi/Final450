#include <iostream>
using namespace std;

long long int count(int s[], int m, int n) {
    long long dp[m+1][n+1];
    for(int i=0; i<=m; i++) dp[i][0]=1;
    for(int j=1; j<=n; j++) dp[0][j]=0;
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j]+dp[i][j-s[i-1]];
            }
        }
    }
    return dp[m][n];
}

int main(){
	int n,m;
	cin>>n>>m;
	int arr[m];
	for(int i=0; i<m; i++) cin>>arr[i];
	cout<<count(arr, m, n);
}
