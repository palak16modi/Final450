#include <iostream>
#include <stack>
using namespace std;

bool balancedParanthesis(string s){
	stack<char> stk;
	for(int i=0;i<s.length();i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='['){
			stk.push(s[i]);
		}
		else{
			if(s[i]==')' && stk.top()=='(') {stk.pop(); }
			if(s[i]==']' && stk.top()=='[') {stk.pop(); }
			if(s[i]=='}' && stk.top()=='{') {stk.pop(); }
		}
	}
	if(!stk.empty()) return false;
	else return true;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<balancedParanthesis(s);
	return 0;
}
