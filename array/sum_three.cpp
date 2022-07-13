#include <iostream>
#include <algorithm>
using namespace std;

bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        sort(A, A+n);
        int i,j,k;
        for(i=0;i<n;i++){
            j=i+1; k=n-1;
            
            while(j<k)
            {
                int sum = A[i]+A[j]+A[k];
                //cout<<sum<<" ";
                if(sum<X) j++;
                if(sum>X) k--;
                if(sum==X) return true;
            }
        }
        return false;
    }

int main(int argc, char** argv) {
	int n,X;
	cin>>n>>X;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<find3Numbers(arr, n, X);
	return 0;
}
