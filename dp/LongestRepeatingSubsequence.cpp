// Finding longest repeating subsequence (just small change in LCS

#include <iostream>
using namespace std;

int LongestRepeatingSubsequence(string s){
    // Code here
    int a = s.length();
    int dp[a+1][a+1];
    for(int i=0; i<=a; i++){
        for(int j=0; j<=a; j++){
            if(i==0 || j==0) dp[i][j]=0;
            else{
                if(s[i-1] == s[j-1] && i!=j) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[a][a];
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<LongestRepeatingSubsequence(s);
	return 0;
}
