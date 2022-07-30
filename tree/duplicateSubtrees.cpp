// print all the suplicate subtrees

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

void preorder(Node* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

string solve(Node* root, unordered_map<string, int> &umap, vector<Node*> &v){
    if(!root) return "";
    string left = solve(root->left, umap, v);
    string right = solve(root->right, umap, v);
    string s = to_string(root->data)+"$"+left+"$"+right;
    if(umap[s] == 1) v.push_back(root);
    umap[s]++;
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    // Code here
    unordered_map<string, int> umap;
    vector<Node*> v;
    solve(root, umap, v);
    return v;
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(2);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(4);
	root->right->right = new Node(5);
	vector<Node*> v;
	v = printAllDups(root);
	for(auto i: v){
		preorder(i);
		cout<<endl;
	}
	return 0;
}
