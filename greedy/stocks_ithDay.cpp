//Buy Maximum Stocks if i stocks can be bought on i-th day

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back(make_pair(price[i],i+1));
        }
        sort(v.begin(), v.end());
        int count = 0, rem = k;
        for(int i=0; i<n; i++){
            if(rem>0){
                int t = rem/v[i].first;
                if(t>v[i].second){
                    t = v[i].second;
                }
                rem = rem - (t*v[i].first);
                count = count + t;
                
            }
        }
        return count;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
