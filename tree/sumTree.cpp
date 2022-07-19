// converting a binary tree to sumTree

#include <iostream>
#include <map>
#include <queue>
#include <vector>
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

int toSumTree(Node* node){
    if(node==NULL) return 0;
    if(node->left==NULL && node->right==NULL){
        int val = node->data;
        node->data = 0;
        return val;
    }
    int l = toSumTree(node->left);
    int r = toSumTree(node->right);
    int summ = l+r+node->data;
    node->data = l+r;
    return summ;
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
	toSumTree(root);
	cout<<endl;
	inorder(root);
	return 0;
}
