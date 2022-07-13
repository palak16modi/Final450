// find elements with occurence more than n/k times with (k-1) extra approach O(nk)

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int t=k-1;
	int a[k-1][2];
	for(int i=0; i<t; i++){
		a[i][0]=0;
		a[i][1]=0;
	}
	for(int i=0; i<n; i++){
		int f=0;
		for(int j=0; j<t; j++){
			if(a[j][0]==arr[i]) {
				a[j][1]++;
				f=1;
				break;
			}
		}
		if(f==0){
			for(int j=0; j<t; j++){
				if(a[j][1]==0) {
					a[j][0]=arr[i];
					a[j][1]=1;
					f=1;
					break;
				}
			}
		}
		if(f==0){
			for(int j=0; j<t; j++){
				a[j][1]--;
			}
		}	
	}
	for(int i=0; i<t; i++){
		a[i][1]=0;
	}
	for(int j=0; j<t; j++){
		for(int i=0; i<n; i++){
			if(a[j][0]==arr[i]) a[j][1]++;
		}
	}
	for(int j=0; j<t; j++){
		if(a[j][1]>(n/k))
		cout<<a[j][0]<<" => "<<a[j][1]<<endl;
	}
	return 0;
}
