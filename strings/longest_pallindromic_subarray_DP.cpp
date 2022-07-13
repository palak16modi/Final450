// longest pallindrome subarray using dp. O(n2) + space complexity of O(n2)

#include <iostream>
using namespace std;

string longestPallindromicSubstringDP(string s){
	int l=s.length();
	int dp[l][l];
	for(int p=0; p<l; p++){
		for(int q=0;q<l; q++){
			dp[p][q]=0;
		}
	}
	int i=0;
	while(i<l) {dp[i][i]=1; i++;}
	i=0;
	int j=1;
	while(i<l && j<l) {
		if(s[i]==s[j]) dp[i][j]=1;
		else dp[i][j]=0;
		i++; j++;
	}
	i=0;
	int c=2;
	while(c<l){
		i=0; j=c++;
		while(i<l && j<l){
			if(s[i]==s[j] && dp[i+1][j-1]==1){
				dp[i][j]=1;
			}
			i++; j++;
		}
	}
	for(int p=0; p<l; p++){
		for(int q=0;q<l; q++){
			cout<<dp[p][q]<<" ";
		}
		cout<<endl;
	}
	
	int ll=0, r=0;
	i=0;j=l-1;
	for(i=0; i<l;i++){
		for(j=i;j<l;j++){
			if(dp[i][j]==1){
				if((r-ll)< (j-i)) {ll=i; r=j;}
			}
		}
	}
	string sans="";
	for(i=ll;i<=r;i++) sans=sans+s[i];
    return sans;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<longestPallindromicSubstringDP(s);
	return 0;
}
