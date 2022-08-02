// spiral raversal of a matrix

#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
    public: 
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> v;
        int i=0,j=0,k=0;
        int t=r*c;
        while(v.size()<t){
            while(j<(c-k)){
                v.push_back(matrix[i][j++]);
            }
            j--; i++;
            if(v.size()==t) break;
            while(i<(r-k)){
                v.push_back(matrix[i++][j]);
                
            }
            j--; i--;
            if(v.size()==t) break;
            while(j>=(0+k)){
                v.push_back(matrix[i][j--]);
            }
            j++; i--;
            while(i>(k+0)){
                v.push_back(matrix[i--][j]);
            }
            j++; i++;
            k++;
        }
        return v;
    }
};


int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
