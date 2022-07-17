// Queue based approach for first non-repeating character in a stream

#include <iostream>
#include <queue>
using namespace std;

string FirstNonRepeating(string s){
		    // Code here
		    string ans="";
		    queue<char> q;
		    int freq[26] = {0};
		    for(int i=0; i<s.length(); i++){
		        q.push(s[i]);
		        freq[s[i]-'a']++;
		        while(!q.empty()){
		            if (freq[q.front() - 'a'] > 1)
                        q.pop();
                    else {
                        ans+=q.front();
                        break;
                    }
		        }
		        if (q.empty())
                    ans+="#";
		    }
		    return ans;
		}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<FirstNonRepeating(s);
	return 0;
}
