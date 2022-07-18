// check if a tree is balanced or not

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

int height(Node* root){
	if(root==NULL) return 0;
	int lh = height(root->left);
	if(lh == -1) return -1;
	int rh = height(root->right);
	if(rh == -1) return -1;
	if(abs(rh-lh)>1) return -1;
	return max(height(root->left),height(root->right))+1;
}

bool isBalanced(Node* root){
	return height(root) != -1;
	
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->left->left->left = new Node(7);
	root->left->left->right = new Node(8);
	// can uncomment and check for unbalanced
	// root->left->left->right->left = new Node(9);
	cout<<isBalanced(root);
	return 0;
}
