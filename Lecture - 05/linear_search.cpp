#include<iostream>
using namespace std;

int linear_search(int a[],int n,int key){
	//Function accepts an array, an integer n, and key to search for and returns the index of the key

	for(int i=0;i<n;i++){
		if(a[i]==key){
			return i;
		}
	}
	return -1;
}

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
		cout<<a[i]<<" "<<endl;
	}
	//Key to search for
	int key;
	cin>>key;
	//Find the index of the key

	int keyMila = linear_search(a,n,key);
	if(keyMila!=-1){
		cout<<"Found at Index "<<keyMila;
	}
	else{
		cout<<"Not found!";
	}


	return 0;
}