// circular queue INCOMPLETE

#include <iostream>
using namespace std;

class Queue{
	int size;
	int f = 0;
	int r = -1;
	int *arr;
	public:
	
	Queue(int n){
		size = n;
		arr = new int[n];
	}
	
	void enque(int x){
		if((r==0 && f==size) || (r == f-1)){
			cout<<"Overflow"<<endl;
		}
		r++;
		arr[r] = x;
		if(r==size) r=0;
	}
	
	void deque(){
		if(f!=-1){
			f++;
			r--;
		} 
	}
	
	void front(){
		if(f<0) {
			cout<<"empty"<<endl;
		}
		cout<<arr[f]<<endl;
	}
	
	void rear(){
		if(r==-1) cout<<"empty"<<endl;
		cout<<arr[r]<<endl;
	}
	
};

int main() {
	Queue q(5);
	q.enque(1);
	q.enque(2);
	q.front();
	q.rear();
	q.enque(3);
	q.enque(5);
	q.deque();
	q.front();
	q.deque();
	q.enque(3);
	q.enque(4);
	q.enque(5);
	q.enque(8);
	return 0;
}
