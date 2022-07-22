//Minimum cost to fill given weight in a bag

#include <iostream>
using namespace std;

int minimumCost(int cost[], int N, int W) 
{ 
    int dp[N+1][W+1];
	 for(int i=0;i<=N;i++)
	     dp[i][0] = 0;
	    for(int j=1;j<=W;j++)
	        dp[0][j]=INT_MAX;
	        
	       for(int i=1;i<=N;i++)
	       {
	           for(int j=1;j<=W;j++)
	           {
	               if(i<=j && cost[i-1]!=-1)
	               {
	                   if(dp[i][j-i]!=INT_MAX)
	                       dp[i][j] = min(cost[i-1]+dp[i][j-i],dp[i-1][j]);
	               
	                   else
	                       dp[i][j] =  dp[i-1][j];
	               }
	               else
	                   dp[i][j] =  dp[i-1][j];
	           }
	       }
	       return dp[N][W]==INT_MAX?-1:dp[N][W];
}

int main(int argc, char** argv) {
	int N,W;
	cin>>N>>W;
	int arr[N];
	for(int i=0; i<N;i++) cin>>arr[i];
	cout<<minimumCost(arr, N, W);
	return 0;
}
