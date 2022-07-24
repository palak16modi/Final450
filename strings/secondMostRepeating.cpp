// second most repeating string in a list of strings

#include <bits/stdc++.h>
using namespace std;

string secFrequent (string arr[], int n)
{
    //code here.
    unordered_map<string ,int> umap;
    for(int i=0; i<n; i++) {
        umap[arr[i]]++;
    }
    unordered_map<string ,int> :: iterator itr, k;
    int m=0;
    string t=arr[0],ans;
    for(itr = umap.begin(); itr != umap.end(); itr++) {
        if(itr->second > m) {
            t = itr->first;
            m = itr->second;
        }
    }
    //cout<<t;
    m=0;
    for(itr = umap.begin(); itr != umap.end(); itr++) {
        if(itr->first != t){
            if(itr->second > m) {ans=itr->first; m=itr->second;}
        }
    }
    return ans;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	string arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<secFrequent(arr, n);
	return 0;
}
