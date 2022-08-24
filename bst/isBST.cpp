// checking if a binary tree is BST or not.

#include <bits/stdc++.h>
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

bool solve(Node* root, int min, int max){
	if(root == NULL) return true;
	else{
		if(min<root->data && root->data<max){
			bool a = solve(root->left,min, root->data);
			bool b = solve(root->right,root->data, max);
			return (a&&b);
		}
		else return false;
	}
}

bool isBST(Node* root){
	return solve(root, INT_MIN, INT_MAX);
}


int main(int argc, char** argv) {
	Node* root = new Node(8);
	root->left = new Node(3);
	root->right = new Node(10);
	root->left->left = new Node(1);
	root->left->right = new Node(6);
	root->right->right = new Node(2);
	root->right->right->left = new Node(13);
	root->left->right->left = new Node(4);
	root->left->right->right = new Node(7);
	bool ans = isBST (root);
	if(ans == true) cout<<"Yes BST";
	if(ans == false) cout<<"No, not BST";
	return 0;
}
