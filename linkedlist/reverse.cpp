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
		
		
		// iterative approach
		void reverseIterative(){
			if(head==NULL || head->next==NULL) return;
			if(head->next->next==NULL){
				head->next->next = head;
				head = head->next;
				head->next->next = NULL;
				return;
			}
			Node* i = head;
			Node* j = head->next;
			Node* k = head->next->next;
			head->next = NULL;
			while(k!=NULL){
				j->next = i;
				i=j;
				j=k;
				k=k->next;
			}
			if(k==NULL) {
				j->next = i;
				head = j;
			}
		}
		
		void addOne(){
			reverseIterative();
			int carry=1;
			Node* temp = head;
			while(temp != NULL){
				if(temp->data != 9){
					temp->data = temp->data+carry;
					carry =0;
					reverseIterative();
					return;
				}
				else{
					//cout<<"here";
					temp->data = 0;
					carry = 1;
				}
				if(temp->next == NULL && carry==1){
					Node* newnode = new Node(1);
					temp->next = newnode;
					carry =0;
					//display();
					reverseIterative();
					//display();
					return;
				}
				temp = temp->next;
			}
			//reverseIterative();
		}
};

int main(int argc, char** argv) {
	linkedlist list;
	list.create(8);
	list.create(9);
	//list.create(9);
	//list.reverseIterative();
	list.addOne();
	list.display();
	return 0;
}
