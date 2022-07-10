// Reverse in group of k

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
		
		void deletenode(int data){
			if(head==NULL) cout<<"Empty";
			Node* temp = head;
			if(temp->data == data){
				head = temp->next;
				return;
			}
			while(temp!=NULL && temp->next->data != data){
				temp = temp->next;
			}
			if(temp==NULL) cout<<"Not present";
			else{
				temp->next = temp->next->next;
			}
		}
		
		// reverse in group
		Node* reverse(Node* head, int k){
			if(head==NULL || head->next==NULL) return head;
			Node* curr = head;
			Node* prev = NULL;
			Node* nextt = NULL;
			int count = 0;
			while(curr!=NULL && count<k){
				nextt = curr->next;
				curr->next = prev;
				prev = curr;
				curr=nextt;
				count++;
			}
			if(nextt!=NULL){
				head->next = reverse(nextt, k);
			}
			return prev;
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
	// list.deletenode(30);
	// list.reverseIterative();
	// list.head = list.reverseRecursive(list.head);
	list.head = list.reverse(list.head, 2);
	list.display();
	return 0;
}
