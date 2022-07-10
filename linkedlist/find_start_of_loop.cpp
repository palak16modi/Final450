// Detect loop with floyd

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
		
		void createLoop(int k){
			Node* temp = head;
			while(temp && k--){
				temp = temp->next;
			}
			Node* last = head;
			while(last->next!=NULL){
				last = last->next;
			}
			last->next = temp;
		}
		
		// find starting of the loop
		void removeDuplicate(){
			Node* temp = head;
		    while(temp->next!=NULL){
		        if(temp->next->data == temp->data){
		            temp->next=temp->next->next;
		        }
		        else{
		            temp = temp->next;
		        }
		    }
		}
		
};

int main(int argc, char** argv) {
	linkedlist list;
	list.create(10);
	list.create(10);
	list.create(20);
	list.create(40);
	list.create(40);
	list.create(50);
	list.create(50);
	list.create(50);
	list.create(50);
	// list.createLoop(2);
	list.removeDuplicate();
	list.display();
	return 0;
}
