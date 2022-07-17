// level order traversal of a binary tree (BFS)

#include <iostream>
#include <queue>
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

void levelorder(Node* root){
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		int s = q.size();
		while(s--){
			Node* temp = q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
		}
	}
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	levelorder(root);
	return 0;
}
