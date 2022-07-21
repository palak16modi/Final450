// Finding the longest common subsequence

#include <iostream>
using namespace std;

int lcs(int x, int y, string s1, string s2)
{
    // your code here
    int a = x, b = y;
    int dp[a+1][b+1];
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            if(i==0 || j==0) dp[i][j]=0;
            else{
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[a][b];
}

int main(int argc, char** argv) {
	string s1, s2;
	cin>>s1>>s2;
	cout<<lcs(s1.length(), s2.length(), s1, s2);
	return 0;
}
