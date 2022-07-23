// Convert a sentence into its equivalent mobile numeric keypad sequence
// Uppercase or space only

#include <bits/stdc++.h>
using namespace std;

string printSequence(string S)
{
    vector<string> v = {
        "2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "666",
        "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"
    };
    string ans="";
    for(int i=0; i<S.length(); i++){
        if(S[i] == ' ') ans+="0";
        else{
            ans += v[S[i]-'A'];   
        }
    }
    return ans;
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<printSequence(s);
	return 0;
}
