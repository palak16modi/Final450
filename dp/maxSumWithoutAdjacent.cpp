#include <iostream>
using namespace std;

int findMaxSum(int *arr, int n) {
    arr[1] = max(arr[0], arr[1]);
    for(int i=2; i<n; i++){
        arr[i] = max(arr[i-1], arr[i]+arr[i-2]);
    }
    return arr[n-1];
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<findMaxSum(arr, n);
	return 0;
}
