// DFS on graph

#include <bits/stdc++.h>
using namespace std;

class Graph{
	public:
		map<int, vector<int>> edges;
		addEdge(int u, int v, bool direction){
			edges[u].push_back(v);
			if(direction == 0){
				edges[v].push_back(u);
			}
		}
		printGraph(){
			for(auto e: edges){
				cout<<e.first<<" -> ";
				for(auto t: e.second){
					cout<<t<<", ";
				}
				cout<<endl;
			}
		}
		
		void printDFS(){
			cout<<"DFS: ";
			unordered_map<int,int> u;
			for(auto e: edges){
				u[e.first] = 0;
			}
			stack<int> s;
			s.push(0);
			while(!s.empty()){
				int t = s.top();
				if(u[t]==0){
					cout<<t<<" ";
					u[t] = 1;
				}
				int si = s.size();
				for(auto x: edges[t]){
					if(u[x]==0) s.push(x);
				}
				int sz = s.size();
				if(si == sz) s.pop();
			}
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n;
	cout<<"enter number of edges ";
	cin>>n;
	int u,v;
	for(int i=0; i<n; i++){
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printGraph();
	g.printDFS();
	return 0;
}

