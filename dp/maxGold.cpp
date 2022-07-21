// maximum gold a thief can steal by moving right, right_up or right_down

#include <iostream>
#include <vector>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> v)
{
    int tm=0, mx=0;
    if(m>1){
        for(int j=m-2; j>=0; j--){
            for(int i=0; i<n; i++){
                int r = v[i][j+1];
                int ru = (i==0)?0:v[i-1][j+1];
                int rd = (i==n-1)?0:v[i+1][j+1];
                v[i][j] += max(r, max(ru,rd));
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        ans = max(ans, v[i][0]);
    }
    return ans;
}

int main(int argc, char** argv) {
	int n,m,k;
	cin>>n>>m;
	vector<vector<int>> v;
	for(int i=0; i<n; i++){
		vector<int> t;
		for(int j=0; j<m; j++){
			cin>>k;
			t.push_back(k);
		}
		v.push_back(t);
	}
	cout<<maxGold(n,m,v);
	return 0;
}
