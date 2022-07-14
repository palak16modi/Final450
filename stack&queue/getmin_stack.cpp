#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char** argv) {
	stack<int, int> stk;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int m=INT_MAX;
	for(int i=0; i<n; i++){
		int m = min(m, arr[i]);
		stk.push(arr[i], m);
	}
	cout<<"minimum element "<<stk.top().second;
	return 0;
}
