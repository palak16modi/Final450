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
		
		void add(Linkedlist l){
			Node* t1 = head;
			Node* t2 = l.head;
			int carry=0;
			while(t1!= NULL && t2!=NULL){
				t1->data = (t1->data + t2->data + carry)%10;
				carry = (t1->data + t2->data + carry)/10;
				t1 = t1->next;
				t2 = t2->next;
			}
			if(t1==NULL && t2!=NULL){
				int sum = (carry + t2->data)%10;
				carry = (carry + t2->data)/10;
				
			}
			
		}
};

int main(int argc, char** argv) {
	Linkedlist ll;
	ll.insert(2);
	ll.insert(1);
	ll.insert(4);
	ll.display();
	Linkedlist lll;
	lll.insert(3);
	lll.insert(1);
	lll.insert(2);
	lll.display();
	return 0;
}
