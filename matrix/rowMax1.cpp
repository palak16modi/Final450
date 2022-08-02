// find first row with maximum number of 1 in a matrix with 0 and 1 and sorted rows

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int i=0,ans=-1,j,c;
	    while(i<m){
	        if(arr[0][i]==1) break;
	        i++;
	    }
	    if(i==m) c=m;
	    else {c=i; ans=0;}
	    for(i=1;i<n;i++){
	        if(arr[i][c-1]==1){
	            for(j=c-1; j>=0; j--){
	                if(arr[i][j]==0) {
	                    ans=i;
	                    c=j+1;
	                    break;
	                }
	            }
	            if(j==-1){
	                ans=i; c=0;
	            }
	        }
	        else continue;
	    }
	    return ans;
	}
    
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

