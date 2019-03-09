#include<iostream>
using namespace std;

bool cowsRakhSkteHai(int stalls[],int n,int c,int d){
	int cows=1;
	int last_cow = stalls[0];

	for(int i=1;i<n;i++){
		if(stalls[i]-last_cow>=d){
			cows++;
			last_cow = stalls[i];
			if(cows==c){
				return true;
			}
		}
	}
	return false;
}

int main(){

	int stalls[] = {1,2,4,8,9}; //sort 
	int n = sizeof(stalls)/sizeof(int);

	int c = 3;

	int s= 0;
	int e = stalls[n-1] - stalls[0];

	int saved = -1;
	while(s<=e){
		int mid =(s+e)/2;
		if(cowsRakhSkteHai(stalls,n,c,mid)){
			s = mid+1;
			saved = mid;
		}
		else{
			e = mid -1;
		}
	}

	cout<<saved<<endl;


	return 0;
}