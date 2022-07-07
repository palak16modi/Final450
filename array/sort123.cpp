// Sort 0,1,2 array

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	int zero=0, one=0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(arr[i]==0) zero++;
		else if(arr[i]==1) one++;
	}
	cout<<"here";
	int i=0;
	while(i<n){
		while(zero--){
			arr[i++]=0;
		}
		while(one--){
			arr[i++]=1;
		}
	    while(i<n){
			arr[i++]=2;
		}
	}
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
