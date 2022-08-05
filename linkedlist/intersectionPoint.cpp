// intersection point of two linked lists

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
		
		Node* createIntersection(Linkedlist l, int k){
			Node* temp = head;
			while(k--){
				temp = temp->next;
			}
			Node* t = l.head;
			while(t->next != NULL){
				t = t->next;
			}
			t->next = temp;
			return l.head;
		}
		
		int intersectPoint(Linkedlist l)
		{
		    // Your Code Here
		    
		    Node* t1 = head;
		    Node* t2 = l.head;
		    int n1 = 0;
		    while(t1 != NULL){
		        n1++;
		        t1 = t1->next;
		    }
		    int n2 = 0;
		    while(t2 != NULL){
		        n2++;
		        t2 = t2->next;
		    }
		    
		    t1 = head;
		    t2 = l.head;
		    
		    if(n1>=n2){
		        int n = n1-n2;
		        while(n--){
		            t1=t1->next;
		        }
		    }
		    if(n2>n1){
		        int n = n2-n1;
		        while(n--){
		            t2=t2->next;
		        }
		    }
		    while(t1 && t2 && t1 != t2){
		        t1 = t1->next;
		        t2 = t2->next;
		        if(t1 == t2) return t1->data;
		    }
		    return -1;
		    
		}
};

int main(int argc, char** argv) {
	Linkedlist ll;
	ll.insert(1);
	ll.insert(9);
	ll.insert(3);
	ll.insert(8);
	ll.insert(4);
	ll.insert(7);
	ll.display();
	Linkedlist lll;
	lll.insert(2);
	lll.insert(9);
	lll.insert(4);
	lll.insert(5);
	lll.display();
	int k = 2;
	lll.head = ll.createIntersection(lll, k);
	cout<<"the intersection point of the list is ";
	cout<<ll.intersectPoint(lll);
	return 0;
}
