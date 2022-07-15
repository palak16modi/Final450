#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string s)
{
    stack<int> stk;
    for(int i=0; i<s.length(); i++){
        if('0'<=s[i] && s[i]<='9'){
            // cout<<"push"<<s[i]<<endl;
            stk.push(s[i]-48);
        }
        else {
            if(stk.size()>1){
                if(s[i]=='+'){
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b+a);
                    // cout<<b<<" "<<a<<endl;
                    // cout<<"+"<<b+a<<endl;
                }
                if(s[i]=='*'){
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b*a);
                    // cout<<b<<" "<<a<<endl;
                    // cout<<"*"<<b*a<<endl;
                }if(s[i]=='-'){
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b-a);
                    // cout<<"-"<<b-a<<endl;
                }if(s[i]=='/'){
                    int a = stk.top();
                    stk.pop();
                    int b = stk.top();
                    stk.pop();
                    stk.push(b/a);
                    // cout<<"/"<<b/a<<endl;
                }
            }
        }
        
    }
    return stk.top();
}

int main(int argc, char** argv) {
	string s;
	cin>>s;
	cout<<evaluatePostfix(s);
	return 0;
}
