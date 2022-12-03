// converting binary tree to binary search tree

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void display(Node* head){
	if(head!=NULL){
		display(head->left);
		cout<<head->data<<" ";
		display(head->right);
	}
}

void inorder(Node* head, vector<int> &v){
	if(head!=NULL){
		inorder(head->left,v);
		v.push_back(head->data);
		inorder(head->right,v);
	}
}

void inordernew(Node* head, vector<int>v, int &i){
	if(head!=NULL){
		inordernew(head->left,v,i);
		head->data = v[i++];
		inordernew(head->right,v,i);
	}
}

void BTtoBST(Node* head){
	vector<int> v;
	inorder(head, v);
	sort(v.begin(), v.end());
	int i=0;
	inordernew(head, v, i);	
}

int main(int argc, char** argv) {
	Node* bt = new Node(1);
	bt->left = new Node(2);
	bt->right = new Node(3);
	bt->left->left = new Node(4);
	display(bt);
	cout<<endl;
	BTtoBST(bt);
	display(bt);
	return 0;
}
