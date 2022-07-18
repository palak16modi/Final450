// Check if all the leaves are at same level or not

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

bool check(Node* root, int level, int* leaflevel){
	if(root==NULL){
		return true;
	}
	if(root->left==NULL && root->right==NULL){
		if(*leaflevel == 0){
			*leaflevel = level;
			return true;
		}
		return level == *leaflevel;
	}
	return check(root->left, level+1, leaflevel) && check(root->right, level+1, leaflevel);
}

bool atSameLevel(Node* root){
	int level=0, leaflevel=0;
	return check(root, level, &leaflevel);
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	// uncomment to check for not at same level
	// root->right->right->right = new Node(8);
	cout<<atSameLevel(root);
}
