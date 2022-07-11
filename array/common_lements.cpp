// commom elements in 3 arrays without extra space

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int n,m,p;
	cin>>n>>m>>p;
	int arr1[n];
	int arr2[m];
	int arr3[p];
	for(int i=0; i<n ; i++) cin>>arr1[i];
	for(int i=0; i<m ; i++) cin>>arr2[i];
	for(int i=0; i<p ; i++) cin>>arr3[i];
	int i=0,j=0,k=0;
	vector<int> ans;
	while(i<n && j<m && k<p){
		if(arr1[i]==arr2[j] && arr1[i]==arr3[k]){
			if(find(ans.begin(), ans.end(), arr1[i]) == ans.end()) ans.push_back(arr1[i]);
			i++; j++; k++;
		} 
		else{
			if(arr1[i] < arr2[j]){
				if(arr1[i] < arr3[k]) i++;
				else k++;
			}
			else{
				if(arr2[j] < arr3[k]) j++;
				else k++;
			}
		}
	}
	for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
	return 0;
}
