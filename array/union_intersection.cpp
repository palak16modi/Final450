// Union and Intersecion of sorted arrays. If not sorted sort them.

#include <iostream>
using namespace std;

void intersection(int a[], int n, int b[], int m){
	int l=0,r=0,f=0;
	while(l<n && r<m){
		if(a[l]==b[r]){
			cout<<a[l]<<" ";
			l++; r++;
			f++;
		}
		else{
			if(a[l]<b[r]) l++;
			else r++;
		}
	}
	if(f==0) cout<<"phi inersecion";
}

void unionn(int a[], int n, int b[], int m){
	int l=0,r=0;
	while(l<n || r<m){
		if(l==n){
			while(r<m){
				cout<<b[r++]<<" ";
			}
		}
		if(r==m){
			while(l<n){
				cout<<a[l++]<<" ";
			}
		}
		if(l<n && r<m) {
			if(a[l]==b[r]){
			cout<<a[l]<<" ";
			l++; r++;
			}
			else{
				if(a[l]<b[r]) {
					cout<<a[l]<<" ";
					l++;
				}
				else{
					cout<<b[r]<<" ";
					r++;
				}
			}
		}
		
	}
}

int main(int argc, char** argv) {
	int n,m;
	cin>>n>>m;
	int a[n], b[m];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];
	intersection(a,n,b,m);
	cout<<endl;
	unionn(a,n,b,m);
	return 0;
}
