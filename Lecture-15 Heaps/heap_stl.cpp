#include<iostream>
#include<queue>
using namespace std;

int main(){

	priority_queue<int> hmax; //maxheap
	priority_queue<int,vector<int>, greater<int> > h; //minheap


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