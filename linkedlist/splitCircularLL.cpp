// spliting circular linked list

#include <bits/stdc++.h>
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
				while(temp->next != head){
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				cout<<temp->data;
			}	
			cout<<endl;
		}
		
		void makeCircular(){
			Node*temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = head;
		}
		
		vector<Node*> splitList(Node *head1_ref, Node *head2_ref)
		{
			vector<Node*> ans;
		    Node* slow = head;
		    Node* fast = head;
		    while(fast->next != head){
		        if(fast->next->next == head){
		            fast->next->next = slow->next;
		            head2_ref = slow->next;
		            slow->next = head;
		            head1_ref = head;
		            ans.push_back(head1_ref);
					ans.push_back(head2_ref);
		            return ans;
		        }
		        else{
		            slow=slow->next;
		            fast = fast->next->next;
		        }
		    }
		    if(fast->next==head){
		        fast->next = slow->next;
		        head2_ref = slow->next;
		        slow->next = head;
		        head1_ref = head;
		        ans.push_back(head1_ref);
				ans.push_back(head2_ref);
		        return ans;
		    }
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
	list.makeCircular();
	Node *head1_ref;
	Node *head2_ref;
	vector<Node*> v;
	v = list.splitList(head1_ref, head2_ref);
	linkedlist one;
	one.head = v[0];
	linkedlist two;
	two.head = v[1];
	one.display();
	two.display();
	return 0;
}



