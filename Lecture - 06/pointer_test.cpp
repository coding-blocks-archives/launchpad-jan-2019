#include<iostream>
using namespace std;




int main(){

	int x = 10;
	int *xptr = &x;
	int *yptr = xptr;

	cout<< x <<endl;
	cout<< xptr <<endl;
	cout<< &xptr <<endl;
	cout<< *(&xptr) <<endl;
	cout<< &(*xptr) <<endl;
	cout<< &(*(&x)) <<endl;
	cout<< *yptr <<endl;
	cout<< yptr <<endl;
	cout<< &yptr <<endl;


	return 0;
}