#include<iostream>
#include<list>
using namespace std;

class Graph{
	list<pair<int,int> > *l;
	int V;
public:
	Graph(int V){
		this->V = V;
		l = new list<pair<int,int > >[V];
	}
	void addEdge(int u,int v,int wt){
		l[u].push_back(make_pair(v,wt));
		l[v].push_back(make_pair(u,wt));
	}
	int dfs_helper(int i,bool *visited,int &ans){
		visited[i] = true;
		int sz = 1;

		for(auto jpair:l[i]){
			int j = jpair.first;
			int wt = jpair.second;

			if(!visited[j]){
				int small_sz = dfs_helper(j,visited,ans);
				ans += 2*min(small_sz,V-small_sz)*wt;
				sz += small_sz;
			}
		}
		return sz;
	}

	int dfs(){
		bool *visited = new bool[V]{0};
		int ans=0;
		dfs_helper(0,visited,ans);
		return ans;
	}


};


int main(){
	Graph g(4);

	g.addEdge(0,1,3);
	g.addEdge(1,2,2);
	g.addEdge(3,2,2);

	cout<<g.dfs()<<endl;

	return 0;
}