// Minimum number of flips to make the binary string alternating

#include <iostream>
using namespace std;

int minFlips (string S)
{
    // your code here
    int ans = 0;
    for(int i=0; i<S.length(); i++){
        if(i%2==0 && S[i]=='1') ans++;
        if(i%2==1 && S[i]=='0') ans++;
    }
    int len = S.length();
    ans = min(ans, len-ans);
    return ans;
}
int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<minFlips(s);
	return 0;
}
