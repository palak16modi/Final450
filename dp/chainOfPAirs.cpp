#include <iostream>
#include <algorithm>
using namespace std;

struct val{
	int first;
	int second;
};

static bool compare( val a, val b){
	if(a.second < b.second)
		return 1;
	else 
		return 0;
}

int maxChainLen(struct val p[],int n){
    sort(p, p+n, compare);
    int i=0, j=1, c=0;
    while(i<n){
        if(p[i].second < p[j].first){
            i=j;
            j++;
            c++;
        }
        else j++;
    }
    return c;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	val p[n];
	for(int i=0; i<n; i++){
		cin>>p[i].first>>p[i].second;
	}
	cout<<maxChainLen(p,n);
	return 0;
}
