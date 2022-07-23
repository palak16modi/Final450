#include <iostream>
using namespace std;

int knapSack(int n, int w, int val[], int wt[])
{
    // code here
    int dp[n+1][w+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(j<wt[i-1]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j], val[i-1]+dp[i][j-wt[i-1]]);
            }
        }
    }
    return dp[n][w];
}

int main(int argc, char** argv) {
	int n,w;
	cin>>n>>w;
	int val[n];
	int wt[n];
	for(int i=0; i<n; i++) cin>>val[i];
	for(int i=0; i<n; i++) cin>>wt[i];
	cout<<knapSack(n, w, val, wt);
	return 0;
}
