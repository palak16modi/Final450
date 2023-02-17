// Minimum number of coins needed to sum upto an amount

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b){
	return a>b;
}

vector<int> minimumCoins(int n){
	vector<int> deno = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	sort(deno.begin(), deno.end(), cmp);
	
	vector<int> ans;
	int i=0;
	while(n){
		if(n < deno[i]) i++;
		else{
			n = n - deno[i];
			ans.push_back(deno[i]);
		}
	}
	return ans;
}

int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		int n;
		 cin>>n;
		 vector<int> coins = minimumCoins(n);
		 for( auto x : coins){
		 	cout<<x<<" ";
		 }
		 cout<<endl;
	}
	return 0;
}
