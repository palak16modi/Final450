#include <iostream>
using namespace std;

class Que{
	int arr[5];
	int front=-1;
	int rear=-1;
	void enqueue(int data){
		if(front==-1 && rear==-1){
			front++;
			rear++;
			arr[front]=data;
		}
		else if(front)
	}
};

int main(int argc, char** argv) {
	return 0;
}
