#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<vector<int>> v;
        for(int i=0; i<n; i++){
            vector<int> t;
            t.push_back(end[i]);
            t.push_back(start[i]);
            v.push_back(t);
        }
        
        sort(v.begin(), v.end());
        int s=v[0][1], e=v[0][0];
        int count = 1;
        
        for(int i=1;i<n;i++){
            if(v[i][1]>e) {
                count++;
                //cout<<"i = "<<i<<endl;
                if(v[i][1] < s) s = v[i][1];
                e = v[i][0];
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
