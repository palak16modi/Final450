// checking if linkedlist is circular

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
		
		void makeCircular(){
			Node*temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = head;
		}
		
		int iscircular(){
			Node* start = head;
			Node* temp = head->next;
			while(temp->next != NULL){
				temp = temp->next;
				if(temp == start) return true;
			}
			return false;
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
	cout<< list.iscircular() <<endl;
	list.makeCircular();
	cout<< list.iscircular();
	return 0;
}
