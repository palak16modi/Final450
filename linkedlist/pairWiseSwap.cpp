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
		
		Node* solve(Node* head){
	        if(head==NULL) return NULL;
	        if(head->next == NULL) return head;
	        head->next->next = head;
	        head = head->next;
	        //head->next = NULL;
	        head->next->next = NULL;
	        return head;
	    }
	    Node* pairWiseSwap() 
	    {
	        // The task is to complete this method
	        if(head->next==NULL) return head;
	        Node* t = head;
	        Node* e;
	        if(head->next->next == NULL){
	            head = solve(t);
	            return head;
	        }
	        Node* k = t->next->next;
	        head = solve(t);
	        e=head->next;
	        t=k;
	        while(t!=NULL && t->next != NULL){
	        	k=t->next->next;
	        	t = solve(t);
	        	e->next = t;
	        	e = t->next;
	        	t=k;
	        	if(t==NULL) cout<<"yes"<<endl;
			}
			if(t!=NULL && t->next==NULL){
				e->next = t;
			}
	        return head;
	    }
		
		
};

int main(int argc, char** argv) {
	linkedlist list;
	list.create(1);
	list.create(2);
	list.create(3);
	list.create(4);
	list.create(5);
	//list.reverseIterative();
	list.head = list.pairWiseSwap();
	list.display();
	//list.display();
	return 0;
}
