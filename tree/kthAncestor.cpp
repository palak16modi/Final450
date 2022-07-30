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

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    vector<int> ans;
    solve(root, node, ans);
    int j=1;
    if(ans.size()==0) return -1;
    for(auto i: ans){
        if(j==k) return i;
        j++;
        if(j==ans.size()+1) return -1;
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
	vector<int> v;
	int n=5;
	int k =2;
	cout<<kthAncestor(root, k, n);
	return 0;
}
