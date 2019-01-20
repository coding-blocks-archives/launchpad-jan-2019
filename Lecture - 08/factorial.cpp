#include <iostream>
using namespace std;

int factorial(int n) {
	// Base Case
	if(n==0) {
		return 1;
	}
	// Assumption;
	int x = factorial(n-1);
	// self work
	int result = n * x;
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<factorial(5);
	return 0;
}
