// Maximum sum of Non-adjacent nodes

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

pair<int,int> solve(Node* root){
    if(root == NULL) return make_pair(0,0);
    pair<int,int> a = solve(root->left);
    pair<int,int> b = solve(root->right);
    return make_pair(root->data+a.second+b.second, max(a.first,a.second)+max(b.first,b.second));
}
int getMaxSum(Node *root) 
{
    // Add your code here
    pair<int,int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout<<getMaxSum(root);
	return 0;
}
