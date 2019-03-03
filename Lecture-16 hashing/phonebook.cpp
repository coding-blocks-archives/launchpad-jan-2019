#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main(){

	map<string,vector<string> >  phonebook;

	phonebook["Arun"].push_back("1001");
	phonebook["Vishesh"].push_back("1002");
	phonebook["Akshat"].push_back("1003");
	phonebook["Kushal"].push_back("1004");
	phonebook["Prateek"].push_back("1005");
	phonebook["Neeraj"].push_back("1006");

	phonebook["Arun"].push_back("1006");

	//phone book
	for(auto p:phonebook){
		string name = p.first;
		
		cout<<name<<"-->";
		for(auto phoneno:p.second){
			cout<<phoneno<<",";
		}
		cout<<endl;

	}
		
		

	return 0;
}