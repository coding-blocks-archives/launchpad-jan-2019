#include<iostream>
#include<map>
using namespace std;


int main(){

	map<int,bool> m;
	//union
	int a[] = {1,2,3,5,4,0};
	int b[] = {2,3,5,9,11,12};

	for(int i=0;i<6;i++){
		m[a[i]] = true;
		m[b[i]] = true;
	}	

	for(auto p:m){
		cout<<p.first<<" ";
	}


	return 0;
}