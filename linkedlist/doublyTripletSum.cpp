// Find triplets with given sum in doubly linked list

#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	Node* next;
	Node* prev;
	
	Node(){
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

class Linkedlist{
	public:
		Node* head;
		
		Linkedlist(){
			head = NULL;
		}
		
		void insert(int val){
			if(head == NULL) {
				Node* newnode = new Node();
				newnode->data = val;
				head = newnode;
			}
			else{
				Node* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				Node* newnode = new Node();
				newnode->data = val;
				newnode->next = NULL;
				newnode->prev = temp;
				temp ->next = newnode;
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
		
		vector<vector<int>> sumTriplets(int sum){
			vector<vector<int>> v;
			
			Node* t = head;
			while(t->next != NULL){
				Node* start = t->next;
				Node* end = t->next;
				while(end->next != NULL){
					end = end->next;
				}
				while(start != end){
					int cursum = start->data+end->data+t->data;
					if(sum > cursum) {
						start=start->next;
					}
					else if(sum < cursum) {
						end = end->prev;
					}
					else if(sum == cursum) {
						vector<int> p;
						p.push_back(t->data);
						p.push_back(start->data);
						p.push_back(end->data);
						v.push_back(p);
						start = start->next;
						end = end->prev;
					}
					if(start->prev == end) break;
				}
				t=t->next;
			}
			return v;
		}
		
		
};

int main(int argc, char** argv) {
	Linkedlist l;
	l.insert(1);
	l.insert(2);
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(8);
	l.insert(9);
	l.display();
	vector<vector<int>> v;
	int sum = 17;
	v = l.sumTriplets(sum);
	if(v.size()==0) cout<<"No pairs"<<endl;
	else{
		for(auto i : v){
			for(auto j : i){
				cout<<j<<" ";
			}
			cout<<endl;
			
		}
	}
	
	return 0;
}
