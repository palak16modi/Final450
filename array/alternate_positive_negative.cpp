// alternate positive and negative elements without using extra space and order of elements matters

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int i=0,j=0;
	while(i<n && j<n) {
		if(i%2==0){
			if(arr[i]<0) i++;
			else{
				j=i+1;
				while(j<n && arr[j]>=0) j++;
				if(j==n) break;
				else{
						int temp = arr[j];
						int k=j-1;
						while(k>=i){
							arr[k+1]=arr[k];
							k--;
						}
						if(k==i-1){
							arr[i] = temp;
						}
					i++;
				}
			}
		}
		else{
			if(arr[i]>0) i++;
			else{
				j=i+1;
				while(j<n && arr[j]<0) j++;
				if(j==n) break;
				else{
						int temp = arr[j];
						int k=j-1;
						while(k>=i){
							arr[k+1]=arr[k];
							k--;
						}
						if(k==i-1){
							arr[i] = temp;
						}
					i++;
				}
			}
		}
	}
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
	return 0;
}
