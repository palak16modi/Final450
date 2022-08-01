// Recursively print all sentences that can be formed from list of word lists

#include <bits/stdc++.h>
using namespace std;

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
