// find the duplicate number in an array of size n+1 where numbers range from 1 to n. the duplicate number would be present twice or more than 
// twice and only one number will be duplicate.

//there are many methods, but this one does not manipulate the existing array and space complexity is O(1)

// Floyd's hare and tortoise cycle detection method.

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int hare=0, tortoise=0;
	do{
		hare=arr[hare];
		tortoise=arr[arr[tortoise]];
	}while(hare!=tortoise);
	tortoise=0;
	while(hare!=tortoise){
		hare=arr[hare];
		tortoise=arr[arr[tortoise]];
	}
	cout<<arr[hare];
	return 0;
}
