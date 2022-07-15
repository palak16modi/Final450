// reversing a stack using recursion
// using the concept of inserting at bottom
// display printing stack in reverse

#include <iostream>
#include <stack>
using namespace std;

stack<int> insertAtBottom(stack<int> s, int x){
	if(s.empty()){
		s.push(x);
		return s;
	}
	if(!s.empty()){
		int a = s.top();
		s.pop();
		s = insertAtBottom(s,x);
		s.push(a);
	}
	return s;
}

stack<int> reverseStack(stack<int> s){
	int i=0, n=s.size();
	while(i<n){
		int a = s.top();
		s.pop();
		s = insertAtBottom(s,a);
		i++;
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
	// display(s);
	s = reverseStack(s);
	display(s);
	return 0;
}
