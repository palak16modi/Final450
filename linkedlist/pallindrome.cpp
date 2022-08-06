// if linkedlist is pallindrome or not

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
		void reverseIterative(Node* slow){
			if(head==slow || head->next==slow) return;
			if(head->next->next==slow){
				head->next->next = head;
				head = head->next;
				head->next->next = slow;
				return;
			}
			Node* i = head;
			Node* j = head->next;
			Node* k = head->next->next;
			head->next = slow;
			while(k!=slow){
				j->next = i;
				i=j;
				j=k;
				k=k->next;
			}
			if(k==slow) {
				j->next = i;
				head = j;
			}
		}
		
		bool isPallindrome(){
			Node* slow = head;
			Node* fast = head;
			while(fast != NULL){
				if(fast->next == NULL){
					//fast = NULL;
					break;
				}
				else{
					if(fast->next->next == NULL){
						fast = NULL;
						slow = slow->next;
						break;
					}
					slow = slow->next;
					fast = fast->next->next;
				}
			}
			reverseIterative(slow);
			if(fast == NULL);
			else if(fast->next == NULL){
				slow=slow->next;
			}
			fast = head;
			while(slow!= NULL){
				if(slow->data == fast->data) {
					slow = slow->next;
					fast = fast->next;
				}
				else return false;
			}
			return true;
		}
};

int main(int argc, char** argv) {
	linkedlist list;
	list.create(1);
	list.create(2);
	list.create(2);
	list.create(1);
	//list.create(2);
	//list.create(4);
	cout<<list.isPallindrome();
	return 0;
}
