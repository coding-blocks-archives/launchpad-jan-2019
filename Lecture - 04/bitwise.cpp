#include<iostream>
using namespace std;


int countBits(int n){
	//set bits count
	int cnt = 0;
	while(n>0){
		cnt += n&1;
		n = n>>1;
	}
	return cnt;
}

int main(){

	// &&,||,! -->Logical Operators 

	// &,|,~,^,>>,<< ---> Bitwise Operators

	int n;
	cin>>n;

	//Single line --> Odd or Even without using %
	//(n&1)?cout<<"ODD" : cout<<"Even";

	cout<<countBits(n);



}