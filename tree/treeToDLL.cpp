// convert a binary tree to a doubly linked list

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void print(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->right;
	}
}

Node* solve(Node* root, Node* &head, Node* &prev, int &f){
	if(root==NULL) return root;
	solve(root->left, head, prev, f);
	if(f==0){
		head = root;
		prev = root;
		f=1;
	}
	else{
		prev->right = root;
		prev->right->left = prev;
		prev= prev->right;
	}
	solve(root->right, head, prev, f);
}

Node* br(Node* root){
	Node* head = NULL;
	Node* prev = NULL;
	int f=0;
	solve(root, head, prev, f);
	return head;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root = br(root);
	print(root);
	return 0;
}
