// BFS on graph

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
		
		void printBFS(){
			cout<<"BFS: ";
			unordered_map<int,int> u;
			for(auto e: edges){
				u[e.first] = 0;
			}
			queue<int> q;
			q.push(0);
			while(!q.empty()){
				int t = q.front();
				for(auto x: edges[t]){
					q.push(x);
				}
				if(u[t]==0){
					cout<<t<<" ";
					u[t] = 1;
				}
				q.pop();
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
	g.printBFS();
	return 0;
}

