// print sum of all paths

#include <iostream>
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

void solve(Node* node, int k, int &count, vector<int> path){
	if(node == NULL) return;
	path.push_back(node->data);
	solve(node->left, k, count, path);
	solve(node->right, k, count, path);
	int sum=0;
	for(int i=path.size()-1; i>=0; i--){
		sum+=path[i];
		if(sum==k) count++;
	}
	path.pop_back();
}

int kSumPaths(Node* root, int k){
	vector<int> path;
	int count = 0;
	solve(root, k, count, path);
	return count;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(1);
	root->left->right = new Node(4);
	root->right->left = new Node(6);
	root->right->right = new Node(1);
	cout<<kSumPaths(root,4);
	return 0;
}
