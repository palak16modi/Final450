// counting the pairs with a given sum

#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	unordered_map<int,int> umap;
	for(int i=0; i<n; i++) cin>>arr[i];
	for(int i=0; i<n; i++){
		umap[arr[i]]++;
	}
	int count=0;
	for(int i=0; i<n; i++){
		int sumreq = k-arr[i];
		if(umap.end() == umap.find(sumreq)) continue;
		else{
			if(arr[i]==sumreq){
				count += umap[sumreq]-1;
				umap[sumreq]--;
			}
			else{
				count += umap[sumreq];
				umap[arr[i]]--;
			}
		}
	}
	cout<<count;
	return 0;
}
