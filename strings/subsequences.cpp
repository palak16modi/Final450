#include <iostream>
#include <vector>
using namespace std;

vector<string> subsequences(string s){
	vector<string> subseq;
	for(int i=0; i<s.length(); i++){
		int cur = subseq.size();
		string t="";
		t=t+s[i];
		subseq.push_back(t);
		for(int j=0; j<cur; j++){
			subseq.push_back(subseq[j]+s[i]);
		}
	}
	return subseq; 
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	vector<string> subseq;
	subseq = subsequences(s);
	for(int i=0; i<subseq.size(); i++){
		cout<<subseq[i]<<" ";
	}
	return 0;
}
