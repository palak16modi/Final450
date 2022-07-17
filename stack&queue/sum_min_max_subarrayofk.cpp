// sum of minimum and maximum element of every subarray of size k

#include <iostream>
#include <queue>
using namespace std;

int minMaxSum(int arr[], int n, int k)
{
	int sum=0;
	deque<int> dq_min, dq_max;
	for(int i=0; i<n; i++){
		while(!dq_min.empty() && dq_min.back()==i-k){
			dq_min.pop_back();
		}
		while(!dq_max.empty() && dq_max.back()==i-k){
			dq_max.pop_back();
		}
		while(!dq_min.empty() && arr[dq_min.back()] > arr[i]){
			dq_min.pop_back();
		}
		while(!dq_max.empty() && arr[dq_max.back()] < arr[i]){
			dq_max.pop_back();
		}
		dq_min.push_back(i);
		dq_max.push_back(i);
		if(i>=k-1){
			cout<<"min "<<arr[dq_min.front()]<<" max "<<arr[dq_max.front()];
			sum = sum+ arr[dq_min.front()] + arr[dq_max.front()];
			cout<<" sum "<<sum<<endl;
		}
	}
	cout<<endl;
	return sum;
}

int main(int argc, char** argv) {
	int n,k;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>k;
	cout<<minMaxSum(arr, n, k);
	return 0;
}
