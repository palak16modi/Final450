// Reverse the array

#include <iostream>
using namespace std;

int main() {
	int n;
	cout<<"enter n"<<endl;
	cin>>n;
	int arr[n];
	cout<<"enter array"<<endl;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0;i<(n/2); i++){
		swap(arr[i],arr[n-i-1]);
	}
	for(int i=0; i<n; i++){
		cout<<arr[i];
	}
	return 0;
}
