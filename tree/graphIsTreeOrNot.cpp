// checking if a graph is tree or not using dfs

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
		
		bool isCyclic(int node, int p, unordered_map<int,int> &u){
			u[node] = 1;
			for(auto x: edges[node]){
				if(u[x] == 0){
					bool cycleDetected = isCyclic(x, node, u);
					if(cycleDetected) return true;
				}
				else{
					if(x != p)
						return true;
				}
			}
			return false;	
		}
		
		void detectCycleUndirectedDFS(){
			int f=0;
			unordered_map<int,int> u;
			unordered_map<int,int> p;
			int st;
			bool start = false;
			for(auto e: edges){
				if(start == false) {
					st = e.first;
					start = true;
				}
				u[e.first] = 0;
			}
			p[st] = -1;
			u[st] = 1;
			for(auto x: edges[st]){
				if(u[x] != 1){
					bool ans = isCyclic(x, st, u);
					if(ans == true) {
						cout<<"Not a tree"<<endl;
						f=1;
					}
				}
			}
			if(f==0) cout<<"Yes a tree";
		}
};

int main(int argc, char** argv) {
	Graph g;
	int n;
	cout<<"enter number of edges ";
	cin>>n;
	int u,v;
	cout<<"enter edges ";
	for(int i=0; i<n; i++){
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printGraph();
	g.detectCycleUndirectedDFS();
	return 0;
}


// checking if a graph is tree or not using bfs
/*
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
		
		void detectCycleUndirectedBFS(){
			int f=0;
			unordered_map<int,int> u;
			unordered_map<int,int> p;
			bool start = false;
			int st;
			for(auto e: edges){
				if(start == false) {
					st = e.first;
					start = true;
				}
				u[e.first] = 0;
			}
			queue<int> q;
			q.push(st);
			p[st] = -1;
			while(!q.empty()){
				int t = q.front();
				if(u[t]==0){
					u[t] = 1;
				}
				q.pop();
				for(auto x: edges[t]){
					if(x != p[t] && u[x]==0) {
						q.push(x);
						p[x] = t;
					}
					else if(x != p[t] && u[x]==1){
						cout<<"Not a tree";
						// cout<<"x "<<x<<endl;
						f=1;
						break;
					}
				}
				if(f==1) break;	
			}
			if(f==0) cout<<"Yes a tree"<<endl;
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
	g.detectCycleUndirectedBFS();
	return 0;
}
*/
