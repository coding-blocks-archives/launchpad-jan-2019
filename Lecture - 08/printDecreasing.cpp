#include <iostream>
using namespace std;

void printDecreasing(int n) {
	if(n==1) { // Base case
		cout<<1<<endl;
		return;
	}
	// Self work
	cout<<n<<endl;
	// Assumption
	printDecreasing(n-1);
	
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
