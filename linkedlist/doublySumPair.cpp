// Find pairs with given sum in doubly linked list

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
		
		vector<pair<int,int>> sumPair(int sum){
			vector<pair<int,int>> v;
			Node* start = head;
			Node* end = head;
			while(end->next != NULL){
				end = end->next;
			}
			while(start != end){
				if(sum > start->data+end->data) start=start->next;
				if(sum < start->data+end->data) end = end->prev;
				if(sum == start->data+end->data) {
					v.push_back(make_pair(start->data, end->data));
					start = start->next;
					end = end->prev;
				}
				if(start->prev == end) break;
			}
			return v;
		}
		
		
};

int main(int argc, char** argv) {
	Linkedlist l;
	l.insert(1);
	l.insert(5);
	l.insert(6);
	l.insert(4);
	l.insert(9);
	l.insert(2);
	l.display();
	vector<pair<int,int>> v;
	int sum = 7;
	v = l.sumPair(sum);
	for(auto i : v){
		cout<<"("<<i.first<<","<<i.second<<") ";
	}
	return 0;
}
