// sort ll of 0,1,2 

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

class Linkedlist{
	public:
		Node* head;
		Linkedlist(){
			head = NULL;
		}
		
		void insert(int data){
			Node* newnode = new Node(data);
			if(head == NULL) head = newnode;
			else{
				Node* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = newnode;
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
		
		void sort012(){
			int zero=0, one=0;
			Node* temp = head;
			while(temp != NULL){
				if (temp->data == 0) zero++;
				else if (temp->data == 1) one++;
				temp = temp->next;
			}
			temp = head;
			while(temp != NULL){
				while(zero--) {
					temp->data = 0;
					temp = temp->next;
				}
				while(one--) {
					temp->data = 1;
					temp = temp->next;
				}
				while(temp!=NULL){
					temp->data = 2;
					temp = temp->next;
				}
			}
		}
};

int main(int argc, char** argv) {
	Linkedlist ll;
	ll.insert(0);
	ll.insert(1);
	ll.insert(1);
	ll.insert(1);
	ll.insert(0);
	ll.insert(2);
	ll.insert(1);
	ll.sort012();
	ll.display();
	
	return 0;
}
