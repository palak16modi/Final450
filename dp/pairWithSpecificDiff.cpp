#include <iostream>
#include <algorithm>
using namespace std;

int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
{ 
    sort(arr, arr + n, greater<int>());
    int sum = 0;
    int i=0;
    while(i<n-1){
        if(abs(arr[i]-arr[i+1]) < k){
            sum += arr[i]+arr[i+1];
            i=i+2;
        }
        else i++;
    }
    return sum;
}
    
int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<maxSumPairWithDifferenceLessThanK(arr, n, k);
 	return 0;
}
