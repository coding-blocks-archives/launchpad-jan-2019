#include<iostream>
using namespace std;


int power(int a,int n){
	//Base Case
	if(n==0){
		return 1;
	}

	//Rec Case
	int smallPower= power(a,n-1);
	return a*smallPower;
}

int fastpower(int a,int n){
	//base case
	if(n==0){
		return 1;
	}
	//rec case
	int smallPower = fastpower(a,n/2);
	smallPower *= smallPower;
	if(n&1){
		return a*smallPower;
	}
	return smallPower;
}
int fastpowerbitmasking(int a,int n){

	int ans = 1;
	while(n>0){
		if(n&1){
			ans = ans*a;
		}
		n = n>>1;
		a = a*a;
	}
	return ans;
}

int main(){
	int a,n;
	cin>>a>>n;

	cout<<power(a,n)<<endl; //n calls n stack frames
	cout<<fastpower(a,n)<<endl; // logn calls logn stack frames
	cout<<fastpowerbitmasking(a,n)<<endl; //logn calls , 1 stack frame



	return 0;
}