// Minimum sum of squares of character counts in a given string after removing k characters

#include <iostream>
#include <queue>
using namespace std;

int minSum(string s, int k){
	if(k>s.length()) return 0;
	int sum=0;
	priority_queue<int> pq;
	int freqarr[26] = {0};
	for(int i=0; i<s.length(); i++){
		freqarr[s[i]-'a']++;
	}
	cout<<endl;
	for(int i=0; i<26; i++){
		cout<<freqarr[i]<<" ";
	}
	for(int i=0; i<26; i++){
		pq.push(freqarr[i]);
	}
	while(k--){
		int temp = pq.top();
		pq.pop();
		temp--;
		pq.push(temp);
	}
	while(!pq.empty()){
		int temp = pq.top();
		sum = sum+ temp*temp;
		pq.pop();
		//cout<<temp<<" "<<sum<<" ";
	}
	return sum;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	int k;
	cin>>k;
	cout<<minSum(s,k);
	return 0;
}
