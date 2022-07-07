// kth min max element using priority queue

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char** argv) {
	int n,k;
	cout<<"Enter n ";
	cin>>n;
	cout<<"Enter k ";
	cin>>k;
	cout<<"Enter elements ";
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int l=0, r=n-1; 
	int min=r-l+1-k, max=k-1;
	priority_queue<int> pq;
        for(int i=l; i<=r; i++){
            pq.push(arr[i]);
        }
        int c=0,minele,maxele;
        for(int i=0; i<(n); i++){
            pq.pop();
            c++;
            if(c==min) minele=pq.top();
            if(c==max) maxele=pq.top();
        }
        cout<<"kth minimun element "<<minele<<endl;
        cout<<"kth maximun element "<<maxele<<endl;
	return 0;
}
