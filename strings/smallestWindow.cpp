// find the smallest window length that contains all the characters of the given string at least one time.

#include <bits/stdc++.h>
using namespace std;

int findSubString(string str)
{
    int ans = INT_MAX;
    set<char> s;
    unordered_map<char,int> u;
    u[str[0]]=1;
    for(int i=0; i<str.length(); i++) s.insert(str[i]);
    int n=s.size();
    int c=1, i=0, j=1;
    while(i<=j && j<str.length()){
        if(c<n) {
            if(u[str[j]]==0) c++;
            u[str[j]]++;
            j++;
        }
        else if(c==n) {
            ans = min(ans, j-i);
            if(u[str[i]] == 1) c--;
            u[str[i]]--;
            i++;
        }
    }
    while(c==n){
        ans = min(ans, j-i);
        if(u[str[i]] == 1) c--;
            u[str[i]]--;
            i++;
    }
    return ans;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<findSubString(s);
	return 0;
}
