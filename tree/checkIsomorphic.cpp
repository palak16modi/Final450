// checking if two trees are isomorphic

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

bool isIsomorphic(Node *root1,Node *root2)
{
	//add code here.
	if(root1==nullptr and root2==nullptr) 
	    return true;
	if(root1==nullptr or root2==nullptr) 
	    return false;
	if(root1->data!=root2->data)
	    return false;
	    
	    return 
	        (isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right))
	        or
	        (isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left));
}

int main(int argc, char** argv) {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	Node* root1 = new Node(1);
	root1->left = new Node(3);
	root1->right = new Node(2);
	root1->left->left = new Node(6);
	root1->left->right = new Node(7);
	root1->right->left = new Node(5);
	root1->right->right = new Node(4);
	cout<<isIsomorphic(root1, root);
	return 0;
}

// this is another approach that I thought of. but the one above is optimized.
/*
vector<vector<int>> ans1;
vector<vector<int>> ans;
vector<int> solve(Node* root){
    vector<int> v;
    vector<int> t;
    if(root == NULL) return v;
    v.push_back(root->data);
    v.push_back(0);
    t = solve(root->left);
    v.insert( v.end(), t.begin(), t.end() );
    v.push_back(0);
    t = solve(root->right);
    v.insert( v.end(), t.begin(), t.end() );
    sort(v.begin(),v.end());
    ans.push_back(v);
    return v;
}
bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
solve(root1);
sort(ans.begin(), ans.end());
ans1 = ans;
ans.clear();
solve(root2);
sort(ans.begin(), ans.end());
if(ans1 == ans) return true;
else false;
}
*/
