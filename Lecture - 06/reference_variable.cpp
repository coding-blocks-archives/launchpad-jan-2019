#include<iostream>
using namespace std;

void inc(int &z){
	z = z + 1;
}
/*
void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}*/

int main(){

	// & --> Bitwise AND, Address Of, Reference Variable
	int x = 10;
	int &y = x; //Init must

	y++;
	inc(x);

	cout<<x <<endl;
	cout<<y <<endl;
	int m = 111;
	swap(x,m);
	cout<<x <<" and "<<m<<endl;


}