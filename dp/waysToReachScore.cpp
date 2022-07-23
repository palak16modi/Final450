// ways to reach a score with possible scores of 3 5 nd 10

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int count(long long int n)
{
	long long int table[n+1],i;
	memset(table, 0, sizeof(table));
	table[0]=1;
	
	int arr[3] = {3,5,10};
	for(int i=0; i<3; i++){
	    for(long long int j=arr[i]; j<=n; j++){
	        if(table[j-arr[i]] > 0) table[j] = table[j-arr[i]] + table[j];
    	}
	}
	return table[n];
}

int main(int argc, char** argv) {
	long long int n;
	cin>>n;
	cout<<count(n);
	return 0;
}
