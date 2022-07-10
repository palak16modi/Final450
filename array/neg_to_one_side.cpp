// Negative to one side. Order does not matter.
// Do try for order maintaing question too

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int l=0, r=n-1;
	while(l<r){
		if(arr[l]>0 && arr[r]<0){
			swap(arr[l],arr[r]);
			l++;
			r--;
		}
		if(arr[l]<0) l++;
		if(arr[r]>0) r--;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
