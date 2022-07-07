#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv) {
	string s = "helloworld";
	unordered_map<char,int> umap;
	for(int i=0; i<s.length(); i++) {
		umap[s[i]]++;
	}
	unordered_map<char,int>:: iterator itr;
	int flag=0;
	for(itr=umap.begin(); itr!=umap.end(); itr++){
		if(itr->second > 1){
			cout<<(itr->first)<<" "<<itr->second<<endl;
			flag=1;
		}
	}
	if(flag==0) cout<<"No duplicate";
	return 0;
}
