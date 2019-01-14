#include<iostream>
using namespace std;

/*
void inc(int no){
	no = no + 1;
}*/
void inc(int *nptr){
	*nptr = *nptr + 1;
}

void swap(int *aptr,int *bptr){

	int temp = *aptr;
	*aptr = *bptr;
	*bptr = temp;
}

int main(){

	int no=10;
	inc(&no);
	cout<<no <<endl;

	int a=10,b=20;
	swap(&a,&b);
	cout<<a<<" and "<<b<<endl;

	return 0;
}