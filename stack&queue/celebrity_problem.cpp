#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int>>& M, int n) 
{
    stack<int> stk;
    int p = 0;
    while(p<n) {stk.push(p); p++;}
    while(stk.size()>=2){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        // cout<<a<<" "<<b<<endl;
        if(M[a][b]==1) stk.push(b);
        if(M[b][a]==1) stk.push(a);
    }
    if(stk.size()==1) {
        int a = stk.top();
        int c=0;
        for(int i=0;i<n;i++){
            if(i!=a && M[i][a]==1) c++;
        }
        if(c==n-1){
            c=0;
            for(int i=0;i<n;i++){
                if(i!=a && M[a][i]==0) c++;
            }
            if(c==n-1) return a;
            else return -1;
        }
        else return -1;
    }
    else if(stk.empty()){
        return -1;
    }
    return -1;
}

int main(int argc, char** argv) {
	int n,t;
	cin>>n;
	vector<vector<int>> M;
	vector<int> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>t;
			m.push_back(t);
		}
		M.push_back(m);
	}
	cout<<celebrity(M,n);
	return 0;
}
