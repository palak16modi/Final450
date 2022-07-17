#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallest(int arr[], int n){
	stack<int> stk;
	vector<int> v;
	for(int i=n-1; i>=0; i--){
		if(i==n-1){
			v.push_back(-1);
			stk.push(arr[i]);
		}
		else{
			while(!stk.empty() && stk.top() > arr[i]){
				stk.pop();
			}
			if(stk.empty()){
				v.push_back(-1);
				stk.push(arr[i]);
			}
			else{
				v.push_back(stk.top());
				stk.push(arr[i]);
			}
		}	
	}
	return v;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	vector<int> v;
	v = nextSmallest(arr,n);
	for(int i=n-1; i>=0; i--) cout<<v[i]<<" ";
	return 0;
}
