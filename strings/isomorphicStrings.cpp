// check if two strings are isomorphic

#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
    if(str1.length() != str2.length()) return false;
    unordered_map<char,int> u;
    set<char> s;
    for(int i=0; i<str1.length(); i++){
        if(u.find(str1[i]) == u.end()) {
            if(s.find(str2[i]) != s.end()) return false;
            else{
                u[str1[i]]=str2[i];
                s.insert(str2[i]);
            }
        }
        else {
            if(u[str1[i]] == str2[i]) continue;
            else return false;
        }
    }
    return true;
    
}

int main(int argc, char** argv) {
	string a,b;
	cin>>a>>b;
	cout<<areIsomorphic(a,b);
	return 0;
}
