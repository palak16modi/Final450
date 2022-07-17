// checking if there are redundant brackets in the string

#include <iostream>
#include <stack>
using namespace std;

int checkRedundancy(string s) {
        // code here
        stack<int> stk;
        int i=0; 
        while(i<s.length()){
            if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                stk.push(s[i]);
                //cout<<"pushed "<<s[i]<<endl;
            }
            else if(s[i]==')') {
                if(!stk.empty() && stk.top() == '(') return 1;
                else if(!stk.empty()){
                    while(stk.top() != '('){
                        stk.pop();
                        //cout<<"poped "<<endl;
                    }
                    stk.pop();
                    //cout<<"popped ("<<endl;
                }
            }
            i++;
            //cout<<i<<endl;
        }
        return 0;
    }

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<checkRedundancy(s);
	return 0;
}
