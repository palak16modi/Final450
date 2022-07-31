// longest prefix which is also suffix

#include <bits/stdc++.h>
using namespace std;

int lps(string s) {
    // Your code goes here
    int n = s.length();
    int lps[n];
    lps[0]=0;
    int i=0, j=1;
    while(j<n){
        if(s[i] == s[j]){
            lps[j]=i+1;
            i++;
            j++;
        }
        else{
            if(i==0) {
                lps[j]=0;
                j++;
            }
            else{
                i=lps[i-1];
            }
        }
    }
    return lps[n-1];
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<lps(s);
	return 0;
}
