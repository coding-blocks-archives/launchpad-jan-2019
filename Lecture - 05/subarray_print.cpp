#include<iostream>
using namespace std;

void printAllSubarray(int a[],int n){

	for(int i=0;i<n;i++){
		
		for(int j=i;j<n;j++){
			//cout<<"("<<i<<","<<j<<")"<<" ";
			//sum = ____
			for(int k=i;k<=j;k++){
				cout<<a[k]<<",";
			}
			//Compare the sum with max sum so far...
			//update max sum 

			cout<<endl;
		}
		//cout<<endl;
	}
}
//Kadane's Algorithm
int maximum_sum(int a[],int n){

	//maximum sum
	int cs = 0;
	int ms  = 0;
	for(int i=0;i<n;i++){
		cs = cs + a[i];
		if(cs<0){
			cs = 0;
		}
		if(cs>ms){
			ms = cs;
		}
	}
	return ms;
}

int main(){


	int a[] = {-1,2,-4,6,3,-2,-1,6,-1};
	int n = sizeof(a)/sizeof(int);

	int i = 0;
	int j = n-1;
	//printAllSubarray(a,n);
	
	cout<<maximum_sum(a,n)<<endl;


	return 0;
}