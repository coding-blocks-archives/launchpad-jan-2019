#include<iostream>
using namespace std;


int main(){

	int n,p;
	cin>>n>>p;


	float ans = 0.0;
	float inc = 1.0;

	for(int times=1;times<=p+1;times++){

		while(ans*ans <=n){
			ans = ans + inc;
		}
		ans = ans-inc;
		inc = inc/10;
	}
	cout<<ans;

	return 0;
}