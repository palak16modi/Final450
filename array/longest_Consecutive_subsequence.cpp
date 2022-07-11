#include <iostream>
#include <unordered_set>
using namespace std;

int main(int argc, char** argv) {
	int n;
	cin>>n;
	int arr[n];
	int ans=0;
	unordered_set<int> u;
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i++) u.insert(arr[i]);
	for(int i=0; i<n; i++){
		if(u.find(arr[i]-1)!=u.end()) i++;
		else{
			int c=0;
			int k=arr[i];
			while(u.find(k)!=u.end()){
				k++;
				c++;
			}
			ans = max(ans,c);
		}
	}
	cout<<ans;
	return 0;
}
