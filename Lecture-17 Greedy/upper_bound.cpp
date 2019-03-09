#include<iostream>
using namespace std;

int upperBound(int *arr,int n,int key){
	int s = 0;
	int e = n-1;
	int saved = -1;
	while(s<=e){
		int m = (s+e)/2;
		if(arr[m]==key){
			saved = m;
			s = m +1;
		}
		else if(arr[m]<key){
			s = m + 1;
		}
		else{
			e = m -1;
		}
	}
	return saved;
}

int main(){

	int arr[] = {1,1,2,2,2,3,3,3,3,5,5,5,5,7};
	int n = sizeof(arr)/sizeof(int);

	int key;
	cin>>key;
	int idx = upperBound(arr,n,key);
	cout<<idx<<endl;

	return 0;
}