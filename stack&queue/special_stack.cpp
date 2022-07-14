// getMin element in the stack in O(1) time.
// Good for OOPS revision LOL.!

#include <iostream>
#include <stack>
using namespace std;



class specialStack{
	class Node{
		public:
		int val;
		int minEle;
		Node(int x, int mnele){
			this->val = x;
			this->minEle = mnele;
		}
	};
	
	stack<Node> s;
	public:
		void push(int x){
			if(s.empty()){
				Node newnode(x,x);
				s.push(newnode);
			}
			else{
				Node newnode(x, min(x,this->s.top().minEle));
				s.push(newnode);
			}
		}
		void pop(){
			this->s.pop();
		}
		int top(){
			int x = this->s.top().val;
			return x;
		}
		int getMin(){
			return this->s.top().minEle;
		}
};
int main(int argc, char** argv) {
	specialStack s;
	s.push(5);
	cout<<s.getMin()<<endl;
	s.push(2);
	s.push(8);
	cout<<s.getMin()<<endl;
	s.push(1);
	cout<<s.top()<<endl;;
	s.pop();
	cout<<s.getMin()<<endl;
	return 0;
}
