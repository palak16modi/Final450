// lowest common ancestor

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

Node* lca(Node* root ,int n1 ,int n2 )
{
   //Your code here 
   if(root==NULL) return NULL;
   if(root->data == n1 || root->data == n2) return root;
   Node* l = lca(root->left, n1, n2);
   Node* r = lca(root->right, n1, n2);
   if(l==NULL && r==NULL) return NULL;
   if(l!=NULL && r==NULL) return l;
   if(l==NULL && r!=NULL) return r;
   if(l!=NULL && r!=NULL) return root;
   
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	int n1=6, n2=7;
	root = lca(root,n1,n2);
	cout<<root->data;
	return 0;
}
