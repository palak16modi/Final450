// rearrange characters in a string such that no two adjacent characters are the same.

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<char,int> a, pair<char,int> b) {
    return a.second < b.second;
}

string rearrangeString(string str)
{
    //code here
    unordered_map<char, int> umap;
    int mx=0;
    for(int i=0; i<str.length(); i++){
        umap[str[i]]++;
        mx = max(mx, umap[str[i]]);
    }
    if(mx > (str.length()-mx+1)) return "-1";
    else {
        priority_queue<pair<int,char>> pq;
        for(auto i : umap){
            pq.push(make_pair(i.second, i.first));
        }
        int i=0;
        while(!pq.empty()){
            char ch= pq.top().second;
            int c = pq.top().first;
            pq.pop();
            while(i<str.length() && c!=0){
                str[i]=ch;
                c--;
                i=i+2;
            }
            if(i==str.length() || i==str.length()+1) {
                i=1;
                while(c--){
                    str[i]=ch;
                    i=i+2;
                }
            }
        }
        return str;
    }
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<rearrangeString(s);
	return 0;
}
