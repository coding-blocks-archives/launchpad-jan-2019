#include<iostream>
#include "hashtable.h"
using namespace std;



int main(){
	hashtable<int> h;

	h.insert("Apple",100);
	h.insert("Mango",200);
	h.insert("Guava",40);
	h.insert("Grape",80);
	h.insert("Kiwi",190);

	

	

	h["papaya"] = 95;
	h["papaya"] += 5;	
	cout<<h["papaya"]<<endl;

	h.show();

	string f;
	cin>>f;

	int *price = h.search(f);
	if(price!=NULL){
		cout<<f<<"costs "<<*price<<endl;
	}
	else{
		cout<<"not found!";
	}


return 0;
}