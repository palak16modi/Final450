//Given an array of strings, return all groups of strings that are anagrams

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string>& words) {
    //code here
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> umap;
    for(auto i : words){
        string s = i;
        sort(s.begin(), s.end());
        umap[s].push_back(i);
    }
    for(auto i : umap){
        ans.push_back(i.second);
    }
    return ans;
}
    
int main(int argc, char** argv) {
	vector<string> words;
	words = {"act","god","cat","dog","tac"};
	vector<vector<string>> ans;
	ans = Anagrams(words);
	for(auto i : ans){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
