// reversing a stack using recursion
// using the concept of inserting at bottom
// display printing stack in reverse

#include <iostream>
#include <stack>
using namespace std;

stack<int> sortedinsert(stack<int> s, int a){
	if(s.empty()){
		s.push(a);
		return s; 
	}
	if(!s.empty() && s.top()>a){
		int t = s.top();
		s.pop();
		s = sortedinsert(s,a);
		s.push(t);
		return s;
	}
	if(!s.empty() && s.top()<=a){
		s.push(a);
		return s;
	}
}

stack<int> sortStack(stack<int> s){
	if(!s.empty()){
		int a = s.top();
		s.pop();
		s = sortStack(s);
		s = sortedinsert(s,a);
	}
	return s;
}

void display(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	stack<int> s;
	int a;
	for(int i=0; i<n; i++) {
		cin>>a;
		s.push(a);
	}
	int mn = INT_MAX;
	s = sortStack(s);
	display(s);
	return 0;
}
