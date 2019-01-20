#include<iostream>
using namespace std;

char spelling[][10] = {"zero","one","two","three","four","five","six"
						"seven","eight","nine"};

void printSent(int no){
	//Base Case no>0
	if(no==0){
		return;
	}

	//Rec Case
	int last_digit = no%10;
	printSent(no/10);
	cout<<spelling[last_digit];
}

int main(){

	int n;
	cin>>n;
	printSent(n);
	return 0;
}