// Maximum difference of zeros and ones in binary string

#include <iostream>
using namespace std;

int maxSubstring(string s)
{
    int n = s.length();
    int dp[n];
    int t;
    if(s[0]=='0') t=1;
    else t=-1;
    int mx = t;
    dp[0] = t;
    for(int i=1; i<n; i++){
        s[i]=='0' ? t=1 : t=-1;
        dp[i] = max(t+dp[i-1], t);
        mx = max(mx, dp[i]);
    }
    return mx;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<maxSubstring(s);
	return 0;
}
