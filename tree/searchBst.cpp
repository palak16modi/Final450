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

bool search(Node* root, int k){
	if(root == NULL) return "not present";
	cout<<root->data<<endl;
	if(root->data == k) return true;
	else if(root->left == NULL && root->right == NULL) return false;
	else if(k < root->data && root->left!=NULL) search(root->left, k);
	else if(k > root->data && root->right!=NULL) search(root->right, k);
}


int main(int argc, char** argv) {
	Node* root = new Node(8);
	root->left = new Node(3);
	root->right = new Node(10);
	root->left->left = new Node(1);
	root->left->right = new Node(6);
	root->right->right = new Node(14);
	root->right->right->left = new Node(13);
	root->left->right->left = new Node(4);
	root->left->right->right = new Node(7);
	int k = 2;
	bool ans = search(root, k);
	if(ans == true) cout<<"Yes found.";
	if(ans == false) cout<<"No, not found.";
	return 0;
}
