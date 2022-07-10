#include <iostream>
#include <stack>
using namespace std;

void printTopToBottom(stack<int> stk){
	if(stk.empty()){
		return;
	}
	else{
		int x = stk.top();
		stk.pop();
		cout<<x<<" ";
		printTopToBottom(stk);
		stk.push(x);
	}
	
}

int main(int argc, char** argv) {
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	printTopToBottom(stk);
	return 0;
}
