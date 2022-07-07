#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	string S= "palllapg";
	int n=S.length();
	int flag=0;
	    for(int i=0; i<n/2; i++){
	        if(S[i]!=S[n-i-1]){
	        	flag=1;
	            cout<<"NO";
	            break;
	        }
	    }
	    if(flag==0) cout<<"YES";
	return 0;
}
