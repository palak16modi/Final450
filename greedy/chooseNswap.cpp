#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	
	string swapFns(string s, char a, char b){
		for(int i=0; i<s.length(); i++){
			if(s[i] == a) s[i] = b;
			else if(s[i] == b) s[i] = a;
		}
		return s;
	}
	
    string chooseandswap(string s){
    	int n = s.length();
        unordered_map<char, int> umap;
        for(int i=0; i<s.length(); i++){
        	if(umap.find(s[i]) == umap.end())
        	umap[s[i]] = i;
		}
		
		for(int i=0; i<n; i++){
			char temp = s[i];
			for(int j=i+1; j<n; j++){
				if(s[j] < s[i] && umap[s[j]] > umap[s[i]]){
					temp = min(temp, s[j]);	
				}
			}
			if(temp < s[i]) {
				return swapFns(s, s[i], temp);
			}
			
		}
		return s;
    }
    
};

int main(int argc, char** argv) {
	Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
