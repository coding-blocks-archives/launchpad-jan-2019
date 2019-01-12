#include<iostream>
using namespace std;

int findLastBit(int n){

	int pos=0;
	while(n>0){
		int last_bit = (n&1);
		if(last_bit==1){
			return pos;
		}
		pos++;
		n = n>>1;
	}
}

void findUnique(int a[],int n){

	//XOR all the numbers
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = ans^a[i];
	}

	//find the last most set bit index in ans
	int pos = findLastBit(ans);

	//filter all numbers have set bit at position


	int unique_no_1 = 0 ;
	int mask = (1<<pos);
	for(int i=0;i<n;i++){
		if((a[i]&mask) >0){
			unique_no_1 = unique_no_1^a[i];
		}	
	}
	int unique_no_2 = ans^unique_no_1;

	cout<<unique_no_1<<" "<<unique_no_2<<endl;
}

int main(){


	int a[] = {1,2,4,3,6,7,3,7,2,1};
	int n = sizeof(a)/sizeof(int);
	//Find Unique Numbers 2N + 2
	findUnique(a,n);	


	return 0;
}