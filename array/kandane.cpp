#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int max_sum = arr[0],sum_so_far=arr[0];
	for(int i=1;i<n;i++){
		sum_so_far = max(arr[i], sum_so_far+arr[i]);
		max_sum = max(sum_so_far, max_sum);
	}
	cout<<max_sum;
	return 0;
}
