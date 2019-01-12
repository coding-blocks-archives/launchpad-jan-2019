#include<iostream>
using namespace std;


int convertBinaryToDecimal(int n){

	int ans = 0;
	int p = 1;

	for( ;n>0;n=n/10){
		int last_digit = n%10;
		ans = ans + last_digit*p;
		p = p*2;
	}
	return ans;
}

int convertDecimalToBinary(int n){

	int ans = 0;
	int p = 1;

	for( ;n>0;n=n/2){
		int last_digit = n%2;
		ans = ans + last_digit*p;
		p = p*10;
	}
	return ans;
}




int main(){

	int n;
	cin>>n;
	//cout<<convertBinaryToDecimal(n)<<endl;
	cout<<convertDecimalToBinary(n)<<endl;

	return 0;
}