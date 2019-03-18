#include<iostream>
#include<map>
#include<list>
using namespace std;

class Graph{
	map<string,list<string> > m;

public:
	void add_edge(string a,string b,bool bidir=true){
		m[a].push_back(b);
		if(bidir){
			m[b].push_back(a);
		}
	}
	void print(){
		for(auto p:m){
			cout<<p.first<<" --> ";
			for(auto city:p.second){
				cout<<city<<",";
			}
			cout<<endl;
		}
	}
	//Depth First Search (DFS)
	void traverse_city(string city,map<string,bool> &visited){
		cout<<city<<"--";
		visited[city] = true;

		for(auto neigbour:m[city]){
			if(!visited[neigbour]){
				traverse_city(neigbour,visited);
			}
		}
	}
	void traverse_india(string start){
		map<string,bool> visited;
		traverse_city(start,visited);
		cout<<endl;

		for(auto city_pair:m){
			string city = city_pair.first;
			if(!visited[city]){
				traverse_city(city,visited);
				cout<<endl;
			}
		}
	}
};

int main(){

	Graph g;
	g.add_edge("Delhi","Jaipur");
	g.add_edge("Mumbai","Jaipur");
	g.add_edge("Delhi","Amristsar");
	g.add_edge("Delhi","Bhopal");
	g.add_edge("Andaman","Nicobar2");
	g.add_edge("Andaman","Nicobar");
	g.add_edge("Andaman","Portblair");
	g.add_edge("Lakshadweep","Kawaratti");
	
	//g.print();
	g.traverse_india("Delhi");
	return 0;
}