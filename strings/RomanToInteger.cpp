// Returns decimal value of roman numaral

#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &);

int main() {
    string s;
    cin >> s;
    cout << romanToDecimal(s) << endl;
}
int romanToDecimal(string &str) {
    // code here
    int i,ans=0;
    unordered_map<char,int> umap;
    umap['I']=1; umap['V']=5; umap['X']=10; umap['L']=50; umap['C']=100; umap['D']=500; umap['M']=1000;
    if(str.length()==1) return umap[str[0]];    
    else{
        ans=ans+umap[str[0]];
        for(i=1;i<str.length();i++){
            if(umap[str[i]]>umap[str[i-1]]){
                ans=ans - 2*(umap[str[i-1]]);
                ans=ans+umap[str[i]];
            }
            else{
                ans=ans+umap[str[i]];
            }
        }
    }
    return ans;
}
