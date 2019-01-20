#include <iostream>
using namespace std;

int fib(int n) {
	// Base case
	if(n==0 or n==1) {
		return n;
	}
	// Assumption
	int retval1 = fib(n-1);
	int retval2 = fib(n-2);
	// Self work
	int result = retval1 + retval2;
	return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	cout<<fib(6);
	return 0;
}
