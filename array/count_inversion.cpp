#include <iostream>
using namespace std;

long long countInv=0;
long long int merge(long long arr[], long long l, long long mid, long long h){
    long long newarr[h-l+1];
    long long i=l, j=mid+1, k=0;
   
    while(i<=mid && j<=h){
        if(arr[i]<=arr[j]){
            newarr[k++]=arr[i++];
        }
        else{
            newarr[k++]=arr[j++];
            countInv += mid-i+1;
        }
    }
    while(i>mid && j<=h){
        newarr[k++]=arr[j++];
    }
    while(i<=mid && j>h){
        newarr[k++]=arr[i++];
    }
    for(i=0; i<k; ++i){
        arr[i+l]=newarr[i];
    }
}

void merge_sort(long long arr[], long long l, long long h){
    if(l<h){
        long long mid = l+(h-l)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    merge_sort(arr, 0, N-1);
    return countInv;
}

int main(int argc, char** argv) {
	long long n;
	cin>>n;
	long long arr[n];
	for(long long i=0; i<n; i++){
		cin>>arr[i];
	}
	cout<<inversionCount(arr, n);
	return 0;
}
