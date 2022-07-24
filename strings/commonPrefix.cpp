// gives the longest common prefix of all strings

#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
if(strs.size()==0) return "";
string s="",a,b;
s=strs[0];
int la,lb,l;
for(int i=1;i<strs.size();i++)
{
    a=strs[i];
    b=s;
    s="";
    la=a.length();
    lb=b.length();
    if(la>lb) l=lb;
    else l=la;
    for(int j=0;j<l;j++)
    {
        if(a[j]==b[j])
        {
            s=s+a[j];
        }
        else
        {
            j=l;
        }
    }
    
}
return s;
}

int main(int argc, char** argv) {
	int n;
	cin>>n;
	vector<string> v;
	string s;
	for(int i=0; i<n; i++) {
		cin>>s;
		v.push_back(s);
	}
	cout<<longestCommonPrefix(v);
	return 0;
}
