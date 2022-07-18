// zigzag traversal of a binary tree (BFS)

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

vector<int> zigzag(Node* root){
	queue<Node*> q;
	vector<int> ans;
	q.push(root);
	int f=0;
	while(!q.empty()){
		vector<int> v;
		int s = q.size();
		while(s--){
			Node* temp = q.front();
			q.pop();
			v.push_back(temp->data);
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
		}
		if(f==0){
			for(int i=0; i<v.size(); i++) ans.push_back(v[i]);
			f=1;
		}
		else{
			for(int i=v.size()-1; i>=0; i--) ans.push_back(v[i]);
			f=0;
		}
	}
	return ans;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->left->left->left = new Node(7);
	root->left->left->right = new Node(8);
	vector<int> v;
	v = zigzag(root);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	return 0;
}
