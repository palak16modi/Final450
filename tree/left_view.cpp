// left view of a binary tree

#include <iostream>
#include <queue>
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

void leftView(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int s = q.size();
		int f=0;
		while(s--){
			Node* temp = q.front();
			q.pop();
			if(f==0) {
				cout<<temp->data<<" ";
				f=1;
			}
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
		}
	}
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->left->left = new Node(8);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right->right = new Node(9);
	root->right->right->right->right = new Node(10);
	leftView(root);
	return 0;
}
