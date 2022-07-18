// bottom view of a binary tree

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

vector<int> bottomView(Node* root) {
	map<int, int> nodes;
	queue<pair<Node*, pair<int,int>>> q;
	vector<int> ans;
	if(root == NULL) return ans;
	q.push(make_pair(root, make_pair(0,0)));
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		Node* node = p.first;
		int x = p.second.first;
		int y = p.second.second;
		nodes[x]=(node->data);
		if(node->left) q.push(make_pair(node->left, make_pair(x-1, y+1)));
		if(node->right) q.push(make_pair(node->right, make_pair(x+1, y+1)));
	}
	for(auto p: nodes){
		ans.push_back(p.second);
	}
	return ans;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(15);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right->right = new Node(17);
	root->right->right->right->right = new Node(27);
	vector<int> v;
	v = bottomView(root);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	return 0;
}
