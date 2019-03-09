#include<iostream>
#include<algorithm>
using namespace std;


int main(){

	int a[] = {1,2,3,4,5,5,5,6,7,10,15,20};
	int n = sizeof(a)/sizeof(int);

	int key;
	cin>>key;
	//Bool (0 or 1 )
	int present = binary_search(a,a+n,key);
	//Index 
	if(present){
		int lb = lower_bound(a,a+n,key)-a;
		cout<<"Present at index"<<lb<<endl;
		int ub = upper_bound(a,a+n,key)-a;
		cout<<"Next bigger Present at index"<<usingb<<endl;

	}
	return 0;
}