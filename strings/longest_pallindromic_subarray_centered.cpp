// will chnage later

#include <iostream>
using namespace std;

int expandfromcntr(string s,int l, int h){
    while(l>=0 && h<s.length() && s[l]==s[h]){
        l--;
        h++;
    }
    return h-l-1;
}
string longestPalin (string s) {
    // code here
    int start=0, end=0;
    for(int i=0; i<s.length(); i++){
        int len1 = expandfromcntr(s,i,i);
        int len2 = expandfromcntr(s,i,i+1);
        int len = max(len1, len2);
        if(end-start < len){
            start = i-(len-1)/2;
            end = i+len/2;
        }
    }
    if(end-start==0) return s.substr(0,1);
    return s.substr(start,end);
}
    
int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<longestPalin(s);
	return 0;
}
