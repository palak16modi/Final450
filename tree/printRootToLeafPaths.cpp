// inorder traversal of a binary tree

#include <iostream>
#include <stack>
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

stack<int> path;
void printpath(){
	if(path.empty()) return;
	int t = path.top();
	path.pop();
	printpath();
	cout<<t<<" ";
	path.push(t);	
}
void rootToLeaf(Node* root){
	if(root==NULL) return;
	path.push(root->data);
	rootToLeaf(root->left);
	if(root->left==NULL && root->right==NULL) {
		printpath();
		cout<<endl;
	}
	rootToLeaf(root->right);
	path.pop();
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	rootToLeaf(root);
	return 0;
}
