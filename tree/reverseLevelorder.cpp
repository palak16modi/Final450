// reverse level order traversal of a binary tree (BFS)
// can use stack also in place of vector

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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

vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        while(s--){
            Node* t = q.front();
            q.pop();
            v.push_back(t->data);
            if(t->right!=NULL) q.push(t->right);
            if(t->left!=NULL) q.push(t->left);
        }
    }
    reverse(v.begin(), v.end());
    return v;
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
	v = reverseLevelOrder(root);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	return 0;
}
