// Find max sum of increasing subsequence
// used the O(n2) method of increasing subsequence with including sum

#include <iostream>
using namespace std;

int maxSumIS(int a[], int n)  
{  
    int sumMax = a[0];
    int dp[n];
    dp[0]=a[0];
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=0; j<i; j++){
            if(a[i]>a[j]) {
                sum = max(sum, dp[j]+a[i]);
            }
            else{
                sum =max(sum, a[i]);
            }
        }
        if(i!=0)
            dp[i] = sum;
        sumMax = max(sum, sumMax);
    }
    // for(int i=0; i<n; i++) cout<<dp[i]<<" ";
    return sumMax;
}  

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<maxSumIS(arr, n);
	return 0;
}
