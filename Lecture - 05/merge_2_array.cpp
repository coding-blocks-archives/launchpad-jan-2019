#include<iostream>
using namespace std;

void merge(int a[],int n,int b[],int m,int c[]){

	int i=0,j=0,k=0;

	while(i<n and j<m){
		if(a[i]<b[j]){
			c[k] = a[i];
			i++;
			k++;
		}
		else{
			c[k] = b[j];
			j++;
			k++;
		}
	}

	//problem?
	while(i<n){
		c[k] = a[i];
		k++; i++;
	}
	while(j<m){
		c[k] = b[j];
		j++; k++;
	}

}

int main(){

	int a[] = {1,3,4,5,7};
	int b[] = {2,4,7,9,10,12,14};
	int c[100];
	int n = sizeof(a)/sizeof(int);
	int m = sizeof(b)/sizeof(int);

	merge(a,n,b,m,c);

	for(int i=0;i<m+n;i++){
		cout<<c[i]<<" ";
	}

	return 0;
}