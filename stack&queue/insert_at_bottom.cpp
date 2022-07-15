// inserting at bottom using recursion
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
	int x;
	cin>>x;
	//display(s);
	s = insertAtBottom(s,x);
	display(s);
	return 0;
}
