// added two numbers given in a form of linked list

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
		
		void reverse(){
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
		
		Node* add(Linkedlist l, Linkedlist ans){
			reverse();
			l.reverse();
			Node* t1 = head;
			Node* t2 = l.head;
			int carry=0;
			while(t1!= NULL && t2!=NULL){
				ans.insert((t1->data + t2->data + carry)%10);
				carry = (t1->data + t2->data + carry)/10;
				t1 = t1->next;
				t2 = t2->next;
			}
			while(t1==NULL && t2!=NULL){
				int sum = (carry + t2->data)%10;
				ans.insert(sum);
				carry = (carry + t2->data)/10;	
				t2 = t2->next;
			}
			while(t1!=NULL && t2==NULL){
				int sum = (carry + t1->data)%10;
				ans.insert(sum);
				carry = (carry + t1->data)/10;	
				t1 = t1->next;
			}
			if(carry != 0){
				ans.insert(carry);
			}
			ans.reverse();
			return ans.head;
		}
};

int main(int argc, char** argv) {
	Linkedlist ll;
	ll.insert(9);
	ll.insert(9);
	ll.insert(9);
	ll.display();
	Linkedlist lll;
	lll.insert(9);
	lll.insert(9);
	//lll.insert(2);
	//lll.insert(8);
	lll.display();
	Linkedlist ans;
	cout<<"the added list is ";
	ans.head = ll.add(lll, ans);
	ans.display();
	return 0;
}
