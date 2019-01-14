#include<iostream>
using namespace std;

void print(int a[],int n){
	cout<<a <<endl;
	cout<<sizof(a)<<endl;
}

int main(){

	int a[100];
	int *b = a;

	cout<<sizeof(a)<<endl; //400
	cout<<sizeof(b)<<endl; //4
	print(a,10);

	cout<<a<<endl; //address of a
	cout<<b<<endl; //address of a

	int x = 10;
	cout<< &x <<endl;
	b = &x ;
	cout<< b <<endl;

	b++;
	cout<<endl;
	//a + 5 = &a[5]
	// a[i] ==> *(a + i)
	return 0;
}