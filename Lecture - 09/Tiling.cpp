#include <iostream>
using namespace std;

int tiling(int n) {
	if(n==1 or n==2 or n==3) {
		return 1;
	}
	if(n==4) {
		return 2;
	}
	return tiling(n-1)+tiling(n-4);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
