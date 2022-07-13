#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
void permutate(string s, int l, int r){
    if(l==r){
        if(find(ans.begin(), ans.end(), s)==ans.end()) ans.push_back(s);
    }
    else{
        for(int i=l; i<=r; i++){
            swap(s[l],s[i]);
            permutate(s,l+1,r);
            swap(s[l],s[i]); //backtracking
        }
    }
}
vector<string>find_permutation(string S)
{
    // Code here there
    permutate(S, 0, S.length()-1);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	find_permutation(s);
	for(int i=0; i<ans.size(); i++) cout<<ans[i]<<endl;
	return 0;
}
