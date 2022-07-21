#include <iostream>
using namespace std;

int editDistance(string s, string t) {
    // Code here
    int a=s.length();
    int b=t.length();
    int dp[a+1][b+1];
    for(int i=0; i<=b; i++) dp[0][i]=i;
    for(int i=0; i<=a; i++) dp[i][0]=i;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
            else {
                int t = min(dp[i-1][j-1],dp[i-1][j]);
                dp[i][j] = 1 + min(t, dp[i][j-1]);
            }
        }
    }
    return dp[a][b];
}

int main(int argc, char** argv) {
	string s,t;
	cin>>s>>t;
	cout<<editDistance(s,t);	
	return 0;
}
