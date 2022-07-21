// Calculating nPr 

#include <iostream>
using namespace std;

int permuatationCoeff(int n, int k){
	int dp[n+1][k+1];
	for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, k); j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j] +
                        (j * dp[i - 1][j - 1]);
            // This step is important
            // as P(i,j)=0 for j>i
            dp[i][j + 1] = 0;
        }
    }
    return dp[n][k];
}

int main(int argc, char** argv) {
	int n,k;
	cin>>n>>k;
	cout<<permuatationCoeff(n, k);
	
	return 0;
}
