// mirror of a binary tree

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

void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void mirror(Node* root){
	if(root == NULL){
		return ;
	}
	if(root->left!=NULL || root->right!= NULL) swap(root->left, root->right);
	if(root->left) mirror(root->left);
	if(root->right) mirror(root->right);
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	inorder(root);
	mirror(root);
	cout<<endl;
	inorder(root);
	return 0;
}
