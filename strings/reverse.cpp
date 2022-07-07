//Reverse string using recursion

#include <iostream>
using namespace std;

string reverse_string(string str, int l, int r){
	if(l<r){
		swap(str[l],str[r]);
		return reverse_string(str, l+1, r-1);
	}
	return str;
}

int main(int argc, char** argv) {
	string s = "waterfall";
	cout<<reverse_string(s, 0, s.length()-1);
	return 0;
}
