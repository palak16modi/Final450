// iterative preorder traversal of a binary tree

#include <iostream>
#include <vector>
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

vector<int> preorderItr(Node* root){
	vector<int> inorderTraversal;
	stack<Node*> stk;
	while(1){
		while(root!=NULL){
			inorderTraversal.push_back(root->data);
			stk.push(root);
			root=root->left;
		}
		if(stk.empty()){
			return inorderTraversal;
		}
		else{
			root = stk.top();
			stk.pop();
			root = root->right;
		}
			
	}
	return inorderTraversal;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	vector<int> v;
	v = preorderItr(root);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	return 0;
}
