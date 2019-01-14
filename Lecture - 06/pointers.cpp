#include<iostream>
using namespace std;




int main(){

	int x = 10;

	// & --> Address Of Operator
	cout<< x <<endl;
	cout<< &x <<endl;

	int a[100];
	//same 
	cout<<a <<endl;
	cout<< &a[0] <<endl;
	cout<< &a <<endl;

	//char array(exception)
	char b[100] = "hello";
	cout<< b <<endl;
	cout<< &b <<endl;
	cout<< &b[0] <<endl;

	// Pointer Variable
	// Spl type of variable which can store address of another variable!
	int y = 20;
	int*yptr;
	yptr = &y;

	cout<<yptr<<endl; //address of y
	cout<<&y<<endl; //address of y
	cout<<&yptr<<endl; //address of yptr 

	int* *zptr = &yptr; //address of yptr
	cout<<zptr<<endl;

	char *aptr;
	int *bptr;

	cout<<sizeof(aptr)<<endl;
	cout<<sizeof(bptr)<<endl;

	//Derefernce Operator
	//* --> Value pointer to by operator
	// 5*3 = 15, int *ptr, third use case

	// &Bucket --> Address
	// *Address -->Bucket

	cout<< *yptr <<endl;
	


	return 0;
}