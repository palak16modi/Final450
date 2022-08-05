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
		
		Node* add(Linkedlist l, Linkedlist ans){
			Node* t1 = head;
			Node* t2 = l.head;
			while(t1!=NULL && t2!=NULL){
				if(t1->data == t2->data){
					ans.insert(t1->data);
					t1 = t1->next;
					t2 = t2->next;
				}
				else if(t1->data < t2->data){
					t1=t1->next;
				}
				else if(t2->data < t1->data){
					t2=t2->next;
				}
			}
			return ans.head;
		}
};

int main(int argc, char** argv) {
	Linkedlist ll;
	ll.insert(1);
	ll.insert(2);
	ll.insert(3);
	ll.display();
	Linkedlist lll;
	lll.insert(2);
	lll.insert(3);
	lll.insert(4);
	lll.insert(5);
	lll.display();
	Linkedlist ans;
	cout<<"the intersection of the list is ";
	ans.head = ll.add(lll, ans);
	ans.display();
	return 0;
}
