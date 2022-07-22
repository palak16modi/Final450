// Maximum size square sub-matrix with all 1s

#include <iostream>
using namespace std;
#define n 6
#define m 5
int maxSizeSq(int a[n][m]){
	int ans = 0;
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(a[i][j]==1 && a[i][j-1]>0 && a[i-1][j]>0 && a[i-1][j-1]>0){
				a[i][j] = min(a[i][j-1], min(a[i-1][j], a[i-1][j-1])) + 1;
				ans = max(ans, a[i][j]);
			}
		}
	}
	return ans;
}

int main(int argc, char** argv) {
	int a[n][m];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin>>a[i][j];
	}
	cout<<maxSizeSq(a);
	return 0;
}
