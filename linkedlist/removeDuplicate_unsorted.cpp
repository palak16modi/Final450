// Remove duplicate from unsorted ll

#include <iostream>
#include <unordered_map>
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
		
		// remove duplicate when sorted
		void removeDuplicateUnsorted(){
			unordered_map<int,int> umap;
		     Node* temp = head;
		     while(temp!=NULL){
		         umap[temp->data]++;
		         temp = temp->next;
		     }
		     temp = head;
		     if(umap[temp->data]>1){
		         umap[temp->data] = 0;
		         // temp=temp->next;
		     }
		        while(temp->next!=NULL){
		            if(umap[temp->next->data]>1){
		                umap[temp->next->data] = 0;
		                temp=temp->next;
		            }
		            else if(umap[temp->next->data]==0){
		                temp->next=temp->next->next;
		            }
		            else if(umap[temp->next->data]==1) temp=temp->next;
		        }
		    }
};

int main(int argc, char** argv) {
	linkedlist list;
	list.create(10);
	list.create(20);
	list.create(60);
	list.create(20);
	list.create(40);
	list.create(50);
	list.create(10);
	list.create(50);
	list.create(50);
	// list.createLoop(2);
	list.removeDuplicateUnsorted();
	list.display();
	return 0;
}
