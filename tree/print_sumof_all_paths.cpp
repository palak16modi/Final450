// print sum of all paths

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

void rootToLeaf(Node* root,int sum){
	if(root==NULL) return;
	sum = sum + root->data;
	if(root->left==NULL && root->right==NULL) {
		cout<<sum<<endl;
		return;
	}
	rootToLeaf(root->left,sum);
	rootToLeaf(root->right,sum);
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	rootToLeaf(root,0);
	return 0;
}
