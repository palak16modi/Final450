#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;
    int dead;
    int profit;
}; 


class Solution 
{
    public:
    	
    static bool cmp1(struct Job a, struct Job b){
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
      sort(arr, arr+n, cmp1);  
    
    
    int maxDead=0;  
	int i =0;
    for(i=0; i<n; i++) {
    	maxDead = max(maxDead, arr[i].dead);
	}
    
    int d[maxDead];
    int count = 0;
    int prof = 0;
    
    for(i=0; i<maxDead; i++) d[i]=-1;
    
    for(i=0; i<n; i++){
    	
    	int t = arr[i].dead - 1;
    	while( t>=0 && d[t] != -1 ) t--;
    	if(t>=0) {
    		d[t] = 1;
    		count++;
    		prof = prof + arr[i].profit;
		}
	}
	
	vector<int> v;
	v.push_back(count);
	v.push_back(prof);
	
	return v;
}
    
};

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


/*
1
5
1 2 100
2 1 19
3 2 27
4 1 25
5 1 15
*/

