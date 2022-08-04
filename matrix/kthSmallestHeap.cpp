// kth smallest element in a row-column wise sorted array

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  priority_queue<int> pq;
  for(int i=n-1; i>=0; i--){
      for(int j=n-1; j>=0; j--){
          if(pq.size()<k) pq.push(mat[i][j]);
          else if(pq.size()==k) {
              pq.pop();
              pq.push(mat[i][j]);
          }
      }
  }
  int ans = pq.top();
  return ans;
}

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	int mat[MAX][MAX];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin>>mat[i][j];
	}
	cout<<kthSmallest(mat, n, k);
	return 0;
}
