// deleting node from circular linkedlist
// node to be deleted should be present

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
				do{
					cout<<temp->data<<" ";
					temp = temp->next;
				}while(temp->next !=head);
				cout<<temp->data;
			}	
		}
		
		void makeCircular(){
			Node*temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = head;
		}
		
		void deleteC(int val){
			Node* t = head;
			if(head->data == val){
				t=head->next;
				while(t->next != head){
					t=t->next;
				}
				t->next = head->next;
				head = head->next;
			}
			else if(head->next->data == val){
					head->next = head->next->next;
			}
			else{
				t = t->next;
				while(t->next->data != val) t=t->next;
				t->next = t->next->next;
			}
			
		}
		
};

int main(int argc, char** argv) {
	linkedlist list;
	list.create(10);
	list.create(20);
	list.create(30);
	list.create(40);
	list.create(50);
	list.create(60);
	list.makeCircular();
	list.deleteC(60);
	list.display();
	return 0;
}
