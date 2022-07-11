#include <iostream>
#include <unordered_set>
using namespace std;

bool isSumZero(int arr[], int n){
	unordered_set<int> us;
	int sum=0;
	for(int i=0; i<n; i++){
		sum = sum+arr[i];
		if(sum==0 || us.find(sum)!=us.end()) return true;
		else us.insert(sum);
	}
	return false;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<isSumZero(arr,n);
	return 0;
}
