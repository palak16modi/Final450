// create a tree from inorder and preorder representation

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

void postorder(Node* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int fetchPosition(int in[], int n, int element){
    for(int i=0; i<n; i++){
        if(in[i]==element)
            return i;
    }
    return -1;
}

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n){
    if(index >= n || inorderStart > inorderEnd){
        return NULL;
    }
    int element = pre[index++];
    int position = fetchPosition(in, n, element);
    Node* root = new Node(element);
    root->left = solve(in, pre, index, inorderStart, position-1, n);
    root->right = solve(in, pre, index, position+1, inorderEnd, n);
    
} 

Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
    return ans;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int pre[n];
	int in[n];
	for(int i=0; i<n; i++) cin>>in[i];
	for(int i=0; i<n; i++) cin>>pre[i];
	Node* root = buildTree(in, pre, n);
	postorder(root);
	return 0;
}
