#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Vector -> ResiZable Array(it can grow or shrink in size automatically)
int main(){

	vector<int> v;
	v.reserve(100);

	for(int i=1;i<=10;i++){
		v.push_back(100-i*i);
	}
	v.pop_back();

	cout<<"Capcity "<<v.capacity()<<"max capacity "<<v.max_size()<<endl;

	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}


	
	return 0;
}