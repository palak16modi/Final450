// diameter of a binary tree 
// 1. It is the number of nodes on longest path between two end nodes
// 2. Path does not need to pass via node
// find node with max sum of left height and right height

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

int maxi = 0;
int diameter(Node* root){
	if(root == NULL){
		return 0;
	}
	int lh = diameter(root->left);
	int rh = diameter(root->right);
	maxi = max(maxi, lh+rh+1);
	return 1+max(lh,rh);
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	diameter(root);
	cout<<maxi;
	return 0;
}
