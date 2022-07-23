// Count the Reversals to balace brackets

#include <bits/stdc++.h>
using namespace std;

int countRev (string s)
{
    // your code here
    if(s.length()%2==1) return -1;
    int countOpen=0, countClose=0, count=0;
    stack<char> stk;
    int ans;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='{') stk.push(s[i]);
        if(s[i]=='}' ){
            if(!stk.empty()) stk.pop();
            else countClose++;
        }
    }
    countOpen = stk.size();
    //cout<<countOpen<<" "<<countClose<<endl;
    if(countOpen%2 == 0) ans = countOpen/2;
    else ans = countOpen/2 + 1;
    if(countClose%2 == 0) ans += countClose/2;
    else ans = ans + countClose/2 + 1;
    return ans;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<countRev(s);
	return 0;
}
