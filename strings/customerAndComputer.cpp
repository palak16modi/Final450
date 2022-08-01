// find Number of customers who could not get a computer

#include <bits/stdc++.h>
using namespace std;

int customerAndComputer(string comp, string people){
	int c = stoi(comp);
	set<char> s;
	int seats = 0, extra=0;
	for(auto i : people){
		if(s.find(i)==s.end()){
			s.insert(i);
			seats++;
			if(seats>c) extra++;
		}
		else{
			s.erase(i);
			seats--;
		}
	}
	return extra;
}

int main(int argc, char** argv) {
	string c,s;
	cin>>c>>s;
	cout<<customerAndComputer(c,s);
	return 0;
}
