#include <iostream>
using namespace std;

int minJumpsToReachEnd(int arr[], int n){
	if(n==1) return 1;
	if(arr[0]==0) return -1;
	int maxR = arr[0];
	int steps = arr[0];
	int jumps = 1;
	for(int i=1; i<n; i++){
		maxR = max(maxR, i+arr[i]);
		if(i>maxR) return -1;
		if(steps>0){
			steps--;
		}
		else{
			jumps++;
			steps = maxR-i;
		}
	}
	return jumps;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	cout<<minJumpsToReachEnd(arr, n);
	
	return 0;
}
