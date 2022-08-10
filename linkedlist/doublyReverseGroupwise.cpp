// doubly reverse in groups

#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node* prev;
		Node* next;
		
		Node(int val){
			this->data = val;
			prev = NULL;
			next = NULL;
		}
};

class doublyll {
	public:
		Node* head;
		doublyll(){
			head = NULL;
		}
		
		void insert(int val){
			if(head == NULL){
				Node* newnode = new Node(val);
				head = newnode;
			}
			else{
				Node* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				Node* newnode = new Node(val);
				temp->next = newnode;
				newnode->prev = temp;
			}
		}
		
		void display(){
			Node* temp = head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		
		
		}
		
		
};

int main(int argc, char** argv) {
	doublyll l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.display();
	l.doublyReverseGroupwise(2);
	l.display();
	return 0;
}
