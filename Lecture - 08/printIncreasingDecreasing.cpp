#include <iostream>
using namespace std;

void printDecInc(int n) {
	if(n==0) { // Base case
		return;
	}
	// Self work
	if(n%2!=0)
		cout<<n<<endl;
	// Assumption
	printDecInc(n-1);
	// Self work
	if(n%2==0)
		cout<<n<<endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
