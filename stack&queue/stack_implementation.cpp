// stack implementation using array

#include <iostream>
using namespace std;

class stk {
	int arr[5];
	int topind = -1;
	public:
		void push(int data){
			if(topind==4){
				cout<<"stack overflow cannot push"<<endl;
			}
			else{
				topind++;
				arr[topind]=data;                                                                                                
			}
		}
		
		void pop(){
			if(topind==-1){
				cout<<"stack empty nothing to pop"<<endl;
			}
			else{
				topind--;
			}
		}
		
		void top(){
			if(topind==-1){
				cout<<"stack empty nothing on top"<<endl;
			}
			else{
				cout<<arr[topind]<<endl;
			}
		}
};

int main(int argc, char** argv) {
	stk s;
	s.push(3);
	s.push(2);
	s.top();
	s.pop();
	s.pop();
	s.top();
	s.pop();
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.top();
	return 0;
}
