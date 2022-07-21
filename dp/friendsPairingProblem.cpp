// a person can either stay single or pair up, find all the posibilities

#include <iostream>
using namespace std;

int countFriendsPairings(int n) 
{ 
    // code here
    if(n==0 || n==1) return 1;
    long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]= (dp[i-1] + (dp[i-2]*(i-1))%1000000007)%1000000007;
    }
    return dp[n];
}
    
int main(int argc, char** argv) {
	int n;
	cin>>n;
	cout<<countFriendsPairings(n);
	return 0;
}
