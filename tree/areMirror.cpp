// Check if two trees are mirror or not

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

bool areMirror(Node* root1, Node* root2){
	if(root1 == NULL && root2 == NULL) return 1;
	if(root1 == NULL || root2 == NULL) return 0;
	return (root1->data == root2->data) &&
		areMirror(root1->left, root2->right) && areMirror(root1->right, root2->left);
}

int main(){
	Node* root1 = new Node(1);
	root1->left = new Node(2);
	root1->right = new Node(3);
	root1->left->left = new Node(4);
	root1->left->right = new Node(5);
	root1->right->left = new Node(6);
	root1->right->right = new Node(7);
	Node* root2 = new Node(1);
	root2->left = new Node(3);
	root2->right = new Node(2);
	root2->left->left = new Node(7);
	root2->left->right = new Node(6);
	root2->right->left = new Node(5);
	root2->right->right = new Node(4);
	// uncomment to check for not at same level
	// root1->right->right->left = new Node(8);
	// root2->right->right = new Node(40);
	cout<<areMirror(root1,root2);
}
