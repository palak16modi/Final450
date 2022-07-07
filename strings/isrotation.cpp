// whether a string is rotation of another

#include <iostream>
#include <queue>
using namespace std;

bool isRotation(string s, string t){
	if(s.length() != t.length()) return false;
	s = s+s;
	if(s.find(t) == string::npos) return false;
	else return true;
}

// this method
bool isRotationQueue(string s, string t){
	if(s.length() != t.length()) return false;
	queue<char> q1;
	queue<char> q2;
	int i;
	for(i=0; i<s.length(); i++){
		q1.push(s[i]);
	}
	for(i=0; i<t.length(); i++){
		q2.push(t[i]);
	}
	for(i=0; i<t.length(); i++){
		char temp = q2.front();
		q2.pop();
		q2.push(temp);
		if(q1==q2) {
			return true;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	string s = "happy";
	string t = "pergh";
	cout<<isRotationQueue(s,t);
	return 0;
}
