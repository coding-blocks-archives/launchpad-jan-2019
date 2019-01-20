#include <iostream>
using namespace std;

void printIncreasing(int n) {
	if(n==0) { // Base case
		return;
	}
	// Assumption
	printIncreasing(n-1);
	// Self work
	cout<<n<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	// printIncreasing(5);
	printDecInc(5);
	return 0;
}
