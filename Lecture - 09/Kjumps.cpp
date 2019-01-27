#include <iostream>
using namespace std;

int kjumps(int n, int k) {
	if(n<0){
		return 0;
	}
	if(n==0) {
		return 1;
	}
	int ans = 0;
	for(int i=1;i<=k;i++) {
		ans+=kjumps(n-i, k);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
