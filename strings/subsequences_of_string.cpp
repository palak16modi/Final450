#include <iostream>
using namespace std;

subsequences(string s){
	vector<string> subseq;
	for(int i=0; i<s.length(); i++){
		int cur = subseq.size();
		subseq.push_back(s[i]);
		for(int j=0; j<cur; i++){
			subseq.push_back(subseq[j]+s[i];
		}
	}
	return subseq;
}

int main(int argc, char** argv) {
	string s;
	vector<string> subseq;
	subseq = subsequences(s);
	for(int i=0; i<subseq.length(); i++){
		cout<<subseq[i]<<" ";
	}
	return 0;
}
