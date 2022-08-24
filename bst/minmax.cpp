// find min and max value in a bst
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

int minValue(Node* root) {
    // Code here
    if(root == NULL) return -1;
    else if(root->left == NULL) return root->data;
    int ans;
    while(root->left!=NULL){
        root = root->left;
        ans = root->data;
    }
    return ans;
}

int maxValue(Node* root) {
    // Code here
    if(root == NULL) return -1;
    else if(root->right == NULL) return root->data;
    int ans;
    while(root->right!=NULL){
        root = root->right;
        ans = root->data;
    }
    return ans;
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
	cout<<minValue(root)<<endl;
	cout<<maxValue(root);
}
