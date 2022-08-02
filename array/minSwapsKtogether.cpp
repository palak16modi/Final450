// Minimum swaps and K together

#include <iostream>
using namespace std;

int minSwap(int arr[], int n, int k) {
    // Complet the function
    int i=0,j,swaps=0,cnt,bad=0;
    for(int i=0; i<n; i++) {
        if(arr[i]<=k) cnt++;
    }
    j=cnt-1;
    cnt=0;
    while(i<=j){
        if(arr[i++]>k) bad++;
    }
    swaps=bad;
    i=1; j++;
    while(j<n){
        if(arr[i-1]<=k) bad++;
        if(arr[j]<=k) bad--;
        swaps=min(swaps,bad);
        i++; j++;
    }
    return swaps;
}


int main(int argc, char** argv) {
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>k;
	cout<<minSwap(arr,n,k);
	return 0;
}
