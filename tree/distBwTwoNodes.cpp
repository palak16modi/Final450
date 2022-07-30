// minimum distance between two nodes in a binary tree

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

int solve(Node* root, int x){
    if(root==NULL) return 0;
    if(root->data == x) return 1;
    int l = solve(root->left, x);
    int r = solve(root->right, x);
    if(l==0 && r==0) return 0;
    if(l==0 && r!=0) return r+1;
    if(l!=0 && r==0) return l+1;
}
Node* lca(Node* root, int a, int b){
    if(root == NULL) return NULL;
    if(root->data == a || root->data == b){
        return root;
    }
    Node* l = lca(root->left, a, b);
    Node* r = lca(root->right, a, b);
    if(l==NULL && r==NULL) return NULL;
    if(l==NULL && r!=NULL) return r;
    if(l!=NULL && r==NULL) return l;
    if(l!=NULL && r!=NULL) return root;
}
int findDist(Node* root, int a, int b) {
    // Your code here
    Node* t = lca(root, a,b);
    int l = solve(t, a)-1;
    int r = solve(t, b)-1;
    //cout<<l<<" "<<r<<endl;
    return l+r;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<findDist(root, 3,7);
	return 0;
}
