#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char** argv) {
	string s;
	cin>>s;
	stack<char> stk;
	for(int i=0; i<s.length(); i++) stk.push(s[i]);
	string srev="";
	for(int i=0; i<s.length(); i++){
		srev=srev+stk.top();
		stk.pop();
	}
	cout<<srev;
	return 0;
}
