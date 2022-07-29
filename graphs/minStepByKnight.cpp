// min steps needed to reach the target by a knight on a chessboard

#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
{
    queue<pair<int,int>> q;
    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) arr[i][j]=0;
    }
    int s=KnightPos[0]-1, e=KnightPos[1]-1;
    int fs=TargetPos[0]-1, fe=TargetPos[1]-1;
    q.push(make_pair(s,e));
    arr[s][e]=1;
    while(!q.empty()){
        auto t = q.front();
        int i = t.first;
        int j = t.second;
        q.pop();
        // top right
        if(i-2>=0 && j+1<n && arr[i-2][j+1]==0){
            q.push(make_pair(i-2, j+1));
            arr[i-2][j+1] = arr[i][j]+1;
        }
        // top left
        if(i-2>=0 && j-1>=0 && arr[i-2][j-1]==0){
            q.push(make_pair(i-2, j-1));
            arr[i-2][j-1] = arr[i][j]+1;
        }
        //right top
        if(i-1>=0 && j+2<n && arr[i-1][j+2]==0){
            q.push(make_pair(i-1, j+2));
            arr[i-1][j+2] = arr[i][j]+1;
        }
        //right bottom
        if(i+1<n && j+2<n && arr[i+1][j+2]==0){
            q.push(make_pair(i+1, j+2));
            arr[i+1][j+2] = arr[i][j]+1;
        }
        //bottom right
        if(i+2<n && j+1<n && arr[i+2][j+1]==0){
            q.push(make_pair(i+2, j+1));
            arr[i+2][j+1] = arr[i][j]+1;
        }
        //bottom left
        if(i+2<n && j-1>=0 && arr[i+2][j-1]==0){
            q.push(make_pair(i+2, j-1));
            arr[i+2][j-1] = arr[i][j]+1;
        }
        //left top
        if(i-1>=0 && j-2>=0 && arr[i-1][j-2]==0){
            q.push(make_pair(i-1, j-2));
            arr[i-1][j-2] = arr[i][j]+1;
        }
        //left bottom
        if(i+1<n && j-2>=0 && arr[i+1][j-2]==0){
            q.push(make_pair(i+1, j-2));
            arr[i+1][j-2] = arr[i][j]+1;
        }
    }
    return arr[fs][fe]-1;
}

int main(int argc, char** argv) {
	int n;
	vector<int> KnightPos;
	vector<int> TargetPos;
	cin>>n;
	int a,b;
	cin>>a>>b;
	KnightPos.push_back(a);
	KnightPos.push_back(b);
	cin>>a>>b;
	TargetPos.push_back(a);
	TargetPos.push_back(b);
	cout<<minStepToReachTarget(KnightPos, TargetPos, n);
	return 0;
}
