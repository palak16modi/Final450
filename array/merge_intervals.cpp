#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.size()==1) return intervals;
    sort(intervals.begin(), intervals.end());
    int start=intervals[0][0], last=intervals[0][1];
    int i=1;
    vector<vector<int>> answer;
    while(i<intervals.size()){
        while(i<intervals.size() && start <= intervals[i][0] &&  intervals[i][0] <= last){
            last = max(last, intervals[i][1]);
            i++;
        }
        if(i==intervals.size()){
            vector<int> ans;
                ans.push_back(start); ans.push_back(last);
                answer.push_back(ans);
        }
        while(i<intervals.size() && intervals[i][0]>last){
            vector<int> ans;
            ans.push_back(start); ans.push_back(last);
            answer.push_back(ans);
            start = intervals[i][0];
            last = intervals[i][1];
            if(i+1 == intervals.size()){
                vector<int> ans;
                ans.push_back(start); ans.push_back(last);
                answer.push_back(ans);
                i++;
            }
            else i++;
            }
        }
    return answer;
}


int main(int argc, char** argv) {
	vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
	intervals = merge(intervals);
	for(int i=0; i<intervals.size(); i++){
		cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
	}
	return 0;
}
