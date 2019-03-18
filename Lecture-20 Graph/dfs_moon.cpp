#include<iostream>
#include<list>
using namespace std;

class Graph{
	list<int> *l;
	int V;
public:
	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}
	void addEdge(int u,int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	int dfs_helper(int i,bool *visited){
		visited[i] = true;
		int sz = 1;

		for(int neighbour:l[i]){
			if(!visited[neighbour]){
				sz += dfs_helper(neighbour,visited);
			}
		}
		return sz;
	}

	int dfs(){
		bool *visited = new bool[V]{0};
		int ans = V*(V-1)/2;
		for(int i=0;i<V;i++){
			if(!visited[i]){
				int sz = dfs_helper(i,visited);
				ans -= (sz)*(sz-1)/2;
			}
		}
		return ans;
	}


};


int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(0,4);
	cout<<g.dfs()<<endl;

	return 0;
}