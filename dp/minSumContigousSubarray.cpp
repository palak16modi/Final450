#include <iostream>
#include <vector>
using namespace std;

int smallestSumSubarray(vector<int>& a){
  //Code here
  int ans=a[0];
  int minSum = a[0];
  for(int i=1; i<a.size(); i++){
      minSum = min(minSum+a[i], a[i]);
      ans = min(ans, minSum);
  }
  return ans;
}

int main(int argc, char** argv) {
	int n,t;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; i++) {
		cin>>t;
		v.push_back(t);
	}
	cout<<smallestSumSubarray(v);
	return 0;
}
