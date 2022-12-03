#include <iostream>
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

int inorderSucc(Node* head){
	while(head!=NULL) {
		cout<<"ewh"<<head->data<<endl;
		if(head->left == NULL){
			if(head->right != NULL) head = head->right;
			else {
				
				cout<<head->data<<"heuwhdiwd"<<endl;
				int t = head->data;
				Node* n = NULL;
				head = n;
				return t;
			}
		}
		else {
			head = head->left;
		}
	}
}

void deleteBST(Node* head, int node){
	if(head != NULL){
		if(head->data == node){
			if(head->left == NULL && head->right == NULL) {
				cout<<head->data<<"here"<<endl;
				//head->data = 90;
				head = NULL;
			}
			else if(head->left == NULL && head->right != NULL) {
				head = head->right;
			}
			else if(head->left != NULL && head->right == NULL) {
				head = head->left;
			}
			else if(head->left != NULL && head->right != NULL) {
				cout<<"herjw"<<endl;
				int succ = inorderSucc(head->right);
				head->data = succ;
				cout<<"ejeid"<<endl;
			}
		}
		else{
			if(head->left != NULL) deleteBST(head->left, node);
			if(head->right != NULL) deleteBST(head->right, node);
		}
	}
}

void display(Node* head){
	if(head != NULL) {
		display(head->left);
		cout<<head->data<<" ";
		display(head->right);
	}
}

int main(int argc, char** argv) {
	Node* head = new Node(50);
	head->left = new Node(30);
	head->left->left = new Node(20);
	head->left->right = new Node(40);
	head->right = new Node(70);
	head->right->left = new Node(60);
	//head->right->right = new Node(80);
	display(head);
	deleteBST(head, 70);
	cout<<"deleted"<<endl;
	display(head);
	return 0;
}
