// Maximum cut segments from a given length nd allowed length to be cut
// recursion and memoization. do remember this

#include <iostream>
#include <vector>
using namespace std;

int solveMem(int n, int x, int y, int z, vector<int> &dp){
   if(n == 0)
       return 0;
   if(n < 0)
       return INT_MIN;
   if(dp[n] != -1)
       return dp[n];
   int a = solveMem(n-x,x,y,z,dp) + 1;
   int b = solveMem(n-y,x,y,z,dp) + 1;
   int c = solveMem(n-z,x,y,z,dp) + 1;
   
   dp[n] = max(a,max(b,c));
   return dp[n];
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    vector<int> dp(n+1, -1);
    int ans = solveMem(n,x,y,z,dp);
    if(ans < 0)
       return 0;
    return ans;
}

int main(int argc, char** argv) {
	int n,x,y,z;
	cin>>n>>x>>y>>z;
	cout<<maximizeTheCuts(n,x,y,z);
	return 0;
}
