// sort a stack using recursion

#include <bits/stdc++.h>
using namespace std;

void insertStk(stack<int> &s, int temp){
    if(s.empty() || temp>=s.top()){
        s.push(temp);
    }
    else{
        int t = s.top();
        s.pop();
        insertStk(s,temp);
        s.push(t);
    }
}

void sortStk(stack<int> &s){
    if(s.empty()) return;
    if(!s.empty()){
        int temp = s.top();
        s.pop();
        sortStk(s);
        insertStk(s,temp);
    }
}

void display(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}


int main(int argc, char** argv) {
	stack<int> s;
	s.push(11);
	s.push(3);
	s.push(32);
	s.push(1);
	s.push(41);
	sortStk(s);
	display(s);
	return 0;
}
