// sum of nodes on longest path from root to node

#include <iostream>
#include <stack>
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

/* my first code
stack<int> stk;
int s=0,len=0;
void print(int sum, int l){
	cout<<sum<<endl;
	if(l>len){
		s = sum;
	}
	if(l==len){
		s = max(s, sum);
	}
}
int sumOfLongestbloodline(Node* root, int sum, int l){
	int ans;
	if(root == NULL) return 0;
	if(root->left==NULL && root->right==NULL) {
		stk.push(root->data);
		sum=sum+root->data;
		print(sum,l);
		stk.pop();
	}
	{
		stk.push(root->data);
		sum=sum+root->data;
		sumOfLongestbloodline(root->left, sum, l+1);
		sumOfLongestbloodline(root->right, sum, l+1);
		stk.pop();
	}
}
*/

// better approach of coding
 void solve(Node* root, int sum, int &maxSum, int l, int &maxLen){
	if(root == NULL){
		if(l>maxLen) {
			maxSum=sum;
			maxLen = l;
		}
		else if(l==maxLen) maxSum = max(sum, maxSum);
		return;
	}
	sum = sum + root->data;
	solve(root->left, sum, maxSum, l+1, maxLen);
	solve(root->right, sum, maxSum, l+1, maxLen);
}

int fns(Node* root){
	int sum=0;
	int maxSum=INT_MIN;
	int l=0;
	int maxLen=0;
	solve(root, sum, maxSum, l, maxLen);
	return maxSum;
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	//root->right->right->left = new Node(8);
	// my approach function call;
	//sumOfLongestbloodline(root, 0, 0);
	//cout<<"sum "<<s;
	cout<<fns(root);
}
