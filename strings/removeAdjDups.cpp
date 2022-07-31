// remove consecutive duplicate elements

#include <bits/stdc++.h>
using namespace std;

string removeConsecutiveCharacter(string S)
{
    // code here.
    stack<char> stk;
    stk.push(S[0]);
    int i=1, l=S.length();
    while(i<l){
        if(stk.top() == S[i]) i++;
        else {
            stk.push(S[i]);
            i++;
        }
    }
    string ans;
    while(!stk.empty()){
        ans = stk.top() + ans;
        stk.pop();
    }
    return ans;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<removeConsecutiveCharacter(s);
	return 0;
}
