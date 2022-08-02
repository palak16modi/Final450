// min swaps for bracket balancing

#include <bits/stdc++.h>
using namespace std;

int minimumNumberOfSwaps(string s){
    // code here 
    int swaps=0;
    int c=0,i=0;
    while(i<s.length()){
        if(s[i]=='[' && s[i+1]==']') i=i+2;
        else if(s[i]==']' && c!=0) {c--; i++;}
        else if(s[i]=='[' && s[i+1]=='[') {c++; i++;}
        else if(s[i]==']' && s[i+1]=='[') {swaps++; i=i+2;}
        else if(s[i]==']' && s[i+1]==']'){
            int j=i+1;
            while(s[j]==']') j++;
            swaps = swaps + (j-i);
            swap(s[i],s[j]);
            i=i+2;
        }
    }
    return swaps;
}

int main(int argc, char** argv) {
	string s;
	cout<<"enter strings of brackets: ";
	cin>>s;
	cout<<minimumNumberOfSwaps(s);
	return 0;
}
