// Finding the longest valid substring
// push the indexes in place of characters

#include <iostream>
#include <stack>
using namespace std;

int findMaxLen(string s) {
        stack<int> stk;
        int n = s.length();
        int i=0, len=0, ans=0;
        stk.push(-1);
        while(i<n){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                if (!stk.empty())
                {
                    stk.pop();
                }
                if (!stk.empty())
                    ans = max(ans, i - stk.top());
                else
                    stk.push(i);
            }
            i++;
        }
        return ans;
    }

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<findMaxLen(s); 
	return 0;
}
