// RabinKarp algorithm

#include <bits/stdc++.h>
using namespace std;

vector <int> search(string pat, string txt)
{
    //code here.
    vector<int> v;
    int l = pat.length();
    int n = txt.length();
    int pans=0; int t=1;
    for(int j=0; j<l; j++){
            pans = (pat[j]-47) + pans*t;
        }
    int first = 0;
    int ans=0;
    for(int j=0; j<(l); j++){
        ans = (txt[j]-47) + ans;
    }
    if(ans == pans) {
            if(pat ==  txt.substr(0, l)) v.push_back(1);}
    for(int i=0; i<(n-l+1); i++){
        int j=i+l;
        ans -= (txt[i]-47);
        ans += (txt[j]-47);
        if(ans == pans) {
            if(pat ==  txt.substr(i+1, l)) v.push_back(i+2);
        }
    }
    if(v.size()==0) v.push_back(-1);
    return v;
}
     
int main(int argc, char** argv) {
	string s,p;
	vector<int> v;
	cin>>s>>p;
	v = search(p,s);
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	return 0;
}
