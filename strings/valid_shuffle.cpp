#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool validShuffle(string a, string b, string s){
	if(a.length()+b.length()!=s.length()) return false;
	a=a+b;
	sort(a.begin(), a.end());
	sort(s.begin(), s.end());
	if(a==s) return true;
	else return false;
	
}

int main(int argc, char** argv) {
	string a,b,s;
	a="ab"; b="cy";
	s="acdb";
	cout<<validShuffle(a,b,s);
	return 0;
}
