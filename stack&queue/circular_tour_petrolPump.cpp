#include <iostream>
#include <queue>
using namespace std;

int tour(vector<vector<int>> p,int n)
    {
       //Your code here
       int rear=0, petrol=0, f=0, deficit=0;
       while(rear < n){
           petrol += (p[rear][0] - p[rear][1]);
           if(petrol >= 0){
               rear++;
           }
           else{
               f=rear+1;
               deficit += petrol;
               petrol = 0;
               rear++;
           }
           
       }
       if(petrol+deficit >=0){
           return f;
       }
       else{
           return -1;
       }
    }

int main(int argc, char** argv) {
	vector<vector<int>> v = {{4,6},{2,3},{7,10}};
	cout<<tour(v, v.size());
	return 0;
}
