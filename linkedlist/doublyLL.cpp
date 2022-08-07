// doubly linkedlist

#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node* next;
	Node* prev;
	
	Node(){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

class Linkedlist{
	public:
		Node* head;
		
		Linkedlist(){
			head = NULL;
		}
		
		void insert(int val){
			if(head == NULL) {
				Node* newnode = new Node();
				newnode->data = val;
				head = newnode;
			}
			else{
				Node* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				Node* newnode = new Node();
				newnode->data = val;
				newnode->next = NULL;
				newnode->prev = temp;
				temp ->next = newnode;
			}
		}
		
		void display(){
			Node* temp = head;
			while(temp != NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
		
		
};

int main(int argc, char** argv) {
	Linkedlist l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
	l.insert(5);
	l.display();
	return 0;
}
