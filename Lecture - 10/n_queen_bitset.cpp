#include<iostream>
using namespace std;


int ld[30]={0},rd[30]={0},col[30]={0};
int total_ways=0;

void nqueen(int i,int n){
	if(i==n){total_ways++; return;}

	//rec case
	for(int j=0;j<n;j++){
		if(col[j]==0 and ld[j-i+n-1]==0 and rd[i+j]==0){
			col[j] = ld[j-i+n-1] = rd[i+j] = 1;
			nqueen(i+1,n);
			col[j] = ld[j-i+n-1] = rd[i+j] = 0;
		}
	}
}


int main(){

	int n;
	cin>>n;
	nqueen(0,n);
	cout<<total_ways<<endl;

	return 0;
}