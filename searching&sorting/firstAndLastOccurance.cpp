#include <iostream>
#include <vector>
using namespace std;

int first(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}
 

int last(int arr[], int low, int high, int x, int n)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1])
            && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}
    
vector<int> find(int arr[], int n , int x )
{
    // code here
    int a = first(arr, 0, n-1, x, n);
    int b = last(arr, 0, n-1, x, n);
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    return v;
    
}

int main(int argc, char** argv) {
	int n,x;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cin>>x;
	vector<int> v;
	v = find(arr,n,x);
	cout<<v[0]<<" "<<v[1];
	return 0;
}
