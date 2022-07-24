#include <bits/stdc++.h>
using namespace std;

void computeLPS(int* lps, int m, string pat){
    int len=0, i=1;
    lps[0]=0;
    while(i<m) {
        if(pat[len] == pat[i]){
            lps[i]=len+1;
            i++;
            len++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
                cout<<len<<endl;
            }
            else{
                lps[i]=0;
                i++;
                cout<<len<<endl;
            }
        }
    }
}
vector <int> search(string pat, string txt)
{
    //code hee.
    vector<int> v;
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    computeLPS(lps, m, pat);
    int i=0, j=-1;
    while(i<n){
        if(txt[i] == pat[j+1]) {
            i++;
            j++;
        }
        if(j==m-1) {
            v.push_back(i-m+1);
            j=lps[j]-1;
        }
        else if(i<n && txt[i]!=pat[j+1]) {
            if(j!=-1) j = lps[j];
            i++;
        }
    }
    if(v.size()==0) v.push_back(-1);
    return v;
}
     

int main(int argc, char** argv) {
	string p,s;
	cin>>s>>p;
	vector<int> v = search(p,s);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	return 0;
}
