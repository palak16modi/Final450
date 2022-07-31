// Minimum number of character added in front to make the string a pallindrome

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

int minChar(string str){
    //Write your code here
    string s;
    s = str;
    reverse(str.begin(), str.end());
    s = s+str;
    int t = lps(s);
    if(str.length() < t) return 0;
    else return str.length()-t;
}  

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<minChar(s);
	return 0;
}
