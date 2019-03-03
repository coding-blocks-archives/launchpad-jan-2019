#include<iostream>
#include "heap.h"
using namespace std;


int main(){

	Heap h(false);
	int arr[] = {1,5,12,7,9,0};
	int n = sizeof(arr)/sizeof(int);

	for(int i=0;i<n;i++){
		h.push(arr[i]);
	}
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}

	return 0;
}