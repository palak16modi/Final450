#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int n,x;
	cin>>n>>x;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	// int i=0,j=0,count=0,cursum=0;
	int s=0, e=0, sum=0, ans=n+1;
        while(e<n){
            while(sum<=x && e<n){
                sum=sum+arr[e];
                e++;
            }
            while(sum>x && s<e){
                if(e-s < ans) ans=e-s;
                sum=sum-arr[s];
                s++;
            }
        }
        cout<<ans;
	return 0;
}
