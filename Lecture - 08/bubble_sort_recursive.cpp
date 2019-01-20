#include<iostream>
using namespace std;

void bubble_sort(int *a,int n){
	//base
	if(n==1 or n==0){
		return;
	}

	//rec case
	for(int i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			swap(a[i],a[i+1]);
		}
	}
	bubble_sort(a,n-1);

}
void bubble_sort2(int *a,int i,int n){
	//base
	if(n==1 or n==0){
		return;
	}

	if(i==n-1){
		bubble_sort2(a,0,n-1);
		return;
	}

	//rec case
	if(a[i]>a[i+1]){
		swap(a[i],a[i+1]);
	}
	bubble_sort2(a,i+1,n);
}

int main(){
	int a[] = {5,4,3,2,1};
	
	//cout<<"Not Sorted!";
	bubble_sort2(a,0,5);
	for(int i=0;i<5;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}