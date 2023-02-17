// Find the minimum and maximum amount to buy all N candies

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> candyStore(int arr[], int n, int k)
    {
        // Write Your Code here
        vector<int> ans;
        sort(arr, arr+n);
        int t = n / (k+1);
        if(n%(k+1) != 0) t = t + 1;
        if(k==0) t=n;
        int count = 0;
        for(int i=0; i<t; i++){
            count = count + arr[i];
        }
        ans.push_back(count);
        count = 0;
        int i = n-1;
        while(t--){
            count = count + arr[i];
            i--;
        }
        ans.push_back(count);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
