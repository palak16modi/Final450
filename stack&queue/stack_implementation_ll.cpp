#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
		Node(){
			this->data = 0;
			this->next = NULL;
		}
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

class stack_linkedlist{
	Node* head;
	public:
		linkedlist(){
			head = NULL;
		}
		
		void create(int data){
			Node* newnode = new Node(data);
			if(head==NULL) {
				head=newnode;
				return;
			}
			else{
				newnode->next = head;
				head = newnode;
				return;
			}
		}
		
		void push(int data){
			create(data);
		}
		
		void pop(){
			if(head==NULL){
				cout<<"stack is empty cannot pop"<<endl;
			}
			else{
				head = head->next;
			}
		}
		
		void top(){
			if(head==NULL){
				cout<<"stack is empty nothing on top"<<endl;
			}
			else{
				cout<<head->data<<endl;
			}
		}
};

int main(int argc, char** argv) {
	stack_linkedlist stk;
	stk.push(1);
	stk.push(2);
	stk.top();
	stk.pop();
	stk.top();
	stk.pop();
	stk.top();
	return 0;
}
