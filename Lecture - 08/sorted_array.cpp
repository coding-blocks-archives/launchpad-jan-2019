#include<iostream>
using namespace std;

bool isSorted(int *a,int n){
	//Base Case
	if(n==1){
		return true;
	}

	//Rec Case
	if(a[0]<a[1] and isSorted(a+1,n-1)){
		return true;
	}
	return false;
}

int main(){
	int a[] = {1,3,5,17,9};
	if(isSorted(a,5)){
		cout<<"Sorted!";
	}
	else{
		cout<<"Not Sorted!";
	}

}