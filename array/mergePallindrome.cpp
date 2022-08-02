// Find minimum number of merge operations to make an array palindrome

#include <iostream>
using namespace std;

int mergePallindrome(int arr[], int n) {
	int i=0, j=n-1,count=0;
	while(i<j){
		if(arr[i]==arr[j]) {
			i++; j--;
		}
		else{
			if(arr[i]>arr[j]){
				arr[j-1] = arr[j]+arr[j-1];
				arr[j]=-1;
				j--;
				count++;
			}
			else{
				arr[i+1] = arr[i]+arr[i+1];
				arr[i]=-1;
				i++;
				count++;
			}
		}
	}
	for(int i=0; i<n; i++) {
		if(arr[i] != -1) cout<<arr[i]<<" ";
	}
	cout<<endl;
	return count;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<mergePallindrome(arr, n);
	return 0;
}
