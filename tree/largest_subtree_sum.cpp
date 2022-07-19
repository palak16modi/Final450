// largest subtree sum of a binary tree

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

int solve(Node* root, int &maxSum){
	if(root==NULL) return 0;
	int sum = root->data + solve(root->left, maxSum) + solve(root->right, maxSum);
	cout<<root->data<<" "<<sum<<endl;
	if(sum > maxSum){
		maxSum = sum;
	}
    return sum;
}

int MaxSubtreeSum(Node* root){
	int maxSum = INT_MIN;
	solve(root,maxSum);
	return maxSum;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<MaxSubtreeSum(root);
	return 0;
}
