// 0/1 Knapsack problem (with items allowed to use only once)

#include <iostream>
using namespace std;

int knapsack(int w[], int p[], int W, int n){
	int dp[n+1][W+1];
	for(int i=0; i<=n; i++) dp[i][0]=0;
	for(int i=0; i<=W; i++) dp[0][i]=0;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=W; j++){
			if(w[i-1] > j) dp[i][j]=dp[i-1][j];
			else{
				dp[i][j] = max(dp[i-1][j], p[i-1]+dp[i-1][j-w[i-1]]);
			}
		}
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=W; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][W];
}

int main(int argc, char** argv) {
	int n,W;
	cin>>n;
	int w[n];
	int p[n];
	for(int i=0; i<n; i++) cin>>w[i];
	for(int i=0; i<n; i++) cin>>p[i];
	cin>>W;
	cout<<knapsack(w, p, W, n);
	return 0;
}
