#include<iostream>
using namespace std;


int main(){


	int a[] = {-2,-1,1,2,3,5,8,9,10};
	int n = sizeof(a)/sizeof(int);

	int i = 0;
	int j = n-1;

	while(i<j){
		if(a[i]+a[j]==4){
			cout<<a[i]<<" and "<<a[j]<<" "<<endl;
			i++; j--;
		}
		else if(a[i]+a[j]<4){
			i++;
		}
		else{
			j--;
		}
	}

	return 0;
}