#include<iostream>
#include<unordered_map>
using namespace std;


int main(){


	unordered_map<string,int> h;

	//insert 1st way
	h.insert(make_pair("apple",100));
	//2nd way
	h["mango"]  = 90;
	//3rd way
	pair<string,int> p;
	p.first = "guava";
	p.second = 87;
	h.insert(p);

	//search
	if(h.count("apple")>0){
		cout<<h["apple"]<<endl;
	}

	// erase
	h.erase("apple");

	//search using iterator and find function
	auto it = h.find("apple");
	if(it!=h.end()){
		cout<<it->second<<endl;
	}
	else{
		cout<<"apple not found!";
	}
	//iterate over all the elements in the table
	for(auto p:h){
		cout<<p.first<<" and "<<p.second<<endl;
	}
	//another way
	for(unordered_map<string,int>::iterator it=h.begin();it!=h.end();it++){
		cout<<it->first;
		cout<<it->second;
	}





	return 0;
}