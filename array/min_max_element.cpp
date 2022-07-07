// Min Max element in the array with minimum comparisons

#include <iostream>
using namespace std;

int main() {
	// the basic method could be of simple traversing he array.
	// this is another method by using pairs.
	int n,min,max;
	cout<<"Enter n ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n%2!=0){
		min = arr[0];
		max = arr[0];
		for(int i=1; i<(n-1); i=i+2){
			if(arr[i]<arr[i+1]){
				if(arr[i]<min) min=arr[i];
				if(arr[i+1]>max) max=arr[i+1];
			}
			else{
				if(arr[i]>max) max=arr[i];
				if(arr[i+1]<min) min=arr[i+1];
			}
		}
	}
	if(n%2==0){
		if(arr[0]<arr[1]) {
			min=arr[0]; max=arr[1];
		}
		else{
			min=arr[1]; max=arr[0];
		}
		for(int i=2; i<(n-1); i=i+2){
			if(arr[i]<arr[i+1]){
				if(arr[i]<min) min=arr[i];
				if(arr[i+1]>max) max=arr[i+1];
			}
			else{
				if(arr[i]>max) max=arr[i];
				if(arr[i+1]<min) min=arr[i+1];
			}
		}
	}
	cout<<min<<" "<<max;
	return 0;
}
