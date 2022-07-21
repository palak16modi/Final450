// calculating value of nCr. here we are creating a pascal triangle

#include <iostream>
using namespace std;

int nCr(int n, int r){
        // code here
         int c[n+1][n+1];
        c[0][0]=0;
        if(n<r){
            return 0;
        }
        for(int i=1;i<=n;i++){
            c[i][0]=1;
            c[i][i]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000007;
            }
        }
        return c[n][r]%1000000007;
    }

int main(int argc, char** argv) {
	int n,r;
	cin>>n>>r;
	cout<<nCr(n,r);
	return 0;
}
