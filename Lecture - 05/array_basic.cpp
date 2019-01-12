#include<iostream>
using namespace std;


int main(){

	//Declare + Init
	int a[100] = {1};

	//Input 
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//Print (Traverse/Iterate) --> Reverse Order
	for(int i=0;i<n;i++){
		cout<<a[n-i-1]<<" "<<endl;
	}

	return 0;
}