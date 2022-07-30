// print all the ancestors of a node 

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


int solve(Node* root, int n, vector<int> &ans){
    if(root == NULL) return 0;
    if(root->data == n) return 1;
    int l = solve(root->left, n, ans);
    int r = solve(root->right, n, ans);
    if(l!=0 || r!=0) {
        ans.push_back(root->data);
        return 1;
    }
    else return 0;
}
vector<int> Ancestors(struct Node *root, int target)
{
     // Code here
     vector<int> ans;
     solve(root, target, ans);
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
	vector<int> v;
	int n=5;
	v= Ancestors(root, n);
	for(auto i: v) cout<<i<<" ";
	return 0;
}
