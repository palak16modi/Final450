#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    	
    bool static cmp(pair<int,int> a, pair<int,int> b){
    	return a.second < b.second;
	}
	
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> train;
    	for(int i=0; i<n; i++){
    		train.push_back({arr[i], dep[i]});
		}
		sort(train.begin(), train.end(), cmp);
		for(auto x:train){
			cout<<x.first<<" "<<x.second;
			cout<<endl;
		}
		
		vector<pair<int,int>> platform;
		platform.push_back({train[0].first, train[0].second});
		
		for(int i=1; i<n; i++){
			int flag=0;
			for(int j=0; j<platform.size(); j++){
				if(flag == 0){
					if(train[i].first >= platform[j].second) {
						platform[j].second = train[i].second;
						flag =1;
					}
				}
				
			}
			if(flag == 0){
				platform.push_back({train[i].first, train[i].second});
			}
		}
		return platform.size();
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
