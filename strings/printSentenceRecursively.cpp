// Recursively print all sentences that can be formed from list of word lists

#include <bits/stdc++.h>
using namespace std;

/*
void fns(string &s, vector<string> &ans, int i, vector<vector<string>> words){
	if(i == words.size()){
		ans.push_back(s);
		return;
	}
	for(int j=0; j<words[i].size(); j++){
		s = s+words[i][j];
		fns(s, ans, i+1, words);
		s=s.substr(0, s.size()-1);
	}
}

int main(int argc, char** argv) {
	vector<vector<string>> words = {{"a","b"}, {"c","d"}, {"e","f","g"}};
	vector<string> ans;
	string s = "";
	fns(s,ans,0,words);
	for(auto i : ans) cout<<i<<" ";
	return 0;
}

*/

void solve(vector<string> &s, vector<vector<string>> &ans, int i, vector<vector<string>> words){
	if(i == words.size()){
		ans.push_back(s);
		for(auto i : s) cout<<i<<" ";
		cout<<endl;
		return;
	}
	for(int j=0; j<words[i].size(); j++){
	    cout<<words[i][j]<<endl;
		s.push_back(words[i][j]);
		for(auto i : s) cout<<i<<" ";
		cout<<endl;
		solve(s, ans, i+1, words);
		s.pop_back();
		for(auto i : s) cout<<i<<" ";
		cout<<endl;
		if(j==words[i].size()) return;
	}
}

vector<vector<string>> sentences(vector<vector<string>>&list){
    //Write your code here
    vector<vector<string>> ans;
	vector<string> s;
	for(auto i : list){
	    for(auto j : i){
	        cout<<j<<" ";
	    }
	}
	solve(s,ans,0,list);
	return ans;
}
int main(int argc, char** argv) {
	vector<vector<string>> words = {{"palak","modi"}, {"have","has"}, {"pencil","violin","book"}};
	vector<vector<string>> ans;
	ans = sentences(words);
	for(auto i : ans) {
		for(auto j : i)
			cout<<j<<" ";
		cout<<endl;
	}
	
	return 0;
}




