#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n){
    vector<long long> ans;
    stack<long long> s;
    for(long long i=n-1; i>=0; i--){
        if(s.empty()) {
            ans.push_back(-1);
            s.push(arr[i]);
        }
        else{
            if(s.top()>arr[i]) {ans.push_back(s.top()); s.push(arr[i]);}
            else{
                while(!s.empty() && s.top()<=arr[i]){
                    s.pop();
                }
                if(s.empty()) ans.push_back(-1);
                else ans.push_back(s.top());
                s.push(arr[i]);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char** argv) {
	long long n;
	cin>>n;
	vector<long long> arr;
	for(int i=0; i<n; i++) cin>>arr[i];
	nextLargerElement
	return 0;
}
