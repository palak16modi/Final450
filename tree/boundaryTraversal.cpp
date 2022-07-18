// Boundary traversal of a binary tree (BFS)

#include <iostream>
#include <queue>
#include <vector>
#include <map>
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

vector<int> in;
void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	if(root->left==NULL && root->right==NULL) in.push_back(root->data);
	inorder(root->right);
}

vector<int> leftBoundary(Node* root){
	vector<int> v;	
	v.push_back(root->data);
	Node* node = root->left;
	while(node != NULL){
		v.push_back(node->data);
		if(node->left != NULL) node = node->left;
		else{
			if(node->right != NULL) node = node->right;
			else node=NULL;
		}
	}
	return v;
}

vector<int> rightBoundary(Node* root){
	Node* node = root->right;
	vector<int> v;
	while(node != NULL){
		v.push_back(node->data);
		if(node->right != NULL) node = node->right;
		else{
			if(node->left != NULL) node = node->left;
			else node=NULL;
		}
	}
	return v;
}

vector<int> boundaryTraversal(Node* root){
	vector<int> ans;
	if(root->left==NULL && root->right==NULL) {
            ans.push_back(root->data);
            return ans;
        }
	ans = leftBoundary(root);
	vector<int> temp;
	inorder(root);
	for(int i=1; i<(in.size()-1); i++) ans.push_back(in[i]);
	temp = rightBoundary(root);
	if(temp.size()==0) ans.push_back(in[in.size()-1]);
	for(int i=temp.size()-1; i>=0; i--) ans.push_back(temp[i]);
	return ans;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->right->right->right = new Node(10);
	vector<int> v;
	v = boundaryTraversal(root);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	return 0;
}
