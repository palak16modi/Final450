// Inorder successor and predecessor of an element in bst

#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	
};

void display(Node* head){
	if(head!=NULL){
		display(head->left);
		cout<<head->data<<" ";
		display(head->right);
	}
}

int successor(Node* head, int element, int &succ){
	if(head!=NULL){
		if(head->data <= element) { successor(head->right, element, succ); }
		if(head->data > element) { succ=head->data; successor(head->left, element, succ); }
	}
}

int predecessor(Node* head, int element, int &pred){
	if(head!=NULL){
		if(head->data < element) { pred=head->data; predecessor(head->right, element, pred); }
		if(head->data >= element) { predecessor(head->left, element, pred); }
	}
}

int main(int argc, char** argv) {
	Node* n = new Node(50);
	n->left = new Node(30);
	n->right = new Node(70);
	n->left->left = new Node(20);
	n->left->right = new Node(40);
	n->right->left = new Node(60);
	n->right->right = new Node(80);
	int succ = NULL;
	int pred = NULL;
	display(n);
	cout<<endl;
	successor(n, 60, succ);
	cout<<succ<<endl;
	predecessor(n, 60, pred);
	cout<<pred;
	return 0;
}

//       50
//   30      70
// 20  40  60  80
