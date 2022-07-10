#include <iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* next;
	
	Node(){
		data =0;
		next = NULL;
	}
	
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

class linkedlist{
	public:
		Node* head;
		linkedlist(){
			head = NULL;
		}
		
		void create(int data){
			Node* newnode = new Node(data);
			
			if(head==NULL) {
				head = newnode;
				return;
			}
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
			if(head==NULL) cout<<"Empty";
			else{
				while(temp->next != NULL){
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				cout<<temp->data;
			}	
		}
		
		void lastToFirst(){
			Node* temp = head;
			while(temp->next->next != NULL){
				temp = temp->next;
			}
			temp->next->next = head;
			head = temp->next;
			temp->next = NULL;
		}
		
		
};

int main(int argc, char** argv) {
	linkedlist list;
	list.create(10);
	list.create(20);
	list.create(30);
	list.create(40);
	list.create(50);
	list.lastToFirst();
	list.display();
	return 0;
}
