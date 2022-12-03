#include <iostream>

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    static bool cmp(struct Item a, struct Item b) {
        double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        double wei = 0.0, vAns=0.0;
        for(int i=0; i<n; i++){
            if((arr[i].weight + wei) <= W) {
                vAns = vAns + arr[i].value;
                wei = wei + arr[i].weight;
            }
            else{
                double t = W-wei;
                vAns += arr[i].value
                          * ((double)t
                             / (double)arr[i].weight);
                break;
            }
        }
        return vAns;
        
    }
        
};

int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
