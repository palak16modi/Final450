// Assembly Line Scheduling

#include <iostream>
#include <vector>
using namespace std;

int carAssembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x){
  int n = a[0].size();
  int dp[2][n+1];
  dp[0][0] = e[0]+a[0][0];
  dp[1][0] = e[1]+a[1][0];
  if(n>1){
      for(int i=1; i<n; i++){
          dp[0][i] = min(dp[0][i-1]+a[0][i], dp[1][i-1]+t[1][i]+a[0][i]);
          dp[1][i] = min(dp[1][i-1]+a[1][i], dp[0][i-1]+t[0][i]+a[1][i]);
      }
  }
  dp[0][n] = dp[0][n-1]+x[0];
  dp[1][n] = dp[1][n-1]+x[1];
  
  int ans = min(dp[0][n], dp[1][n]);
  return ans;
}

int main(int argc, char** argv) {
	vector<vector<int>> a = { { 4, 5, 3, 2 }, 
                   				{ 2, 10, 1, 4 } }; 
    vector<vector<int>> t = { { 0, 7, 4, 5 }, 
                   				{ 0, 9, 2, 8 } }; 
    vector<int> e = { 10, 12 };
	vector<int> x = { 18, 7 }; 
  
    cout << carAssembly(a, t, e, x); 
  
    return 0; 
	return 0;
}
