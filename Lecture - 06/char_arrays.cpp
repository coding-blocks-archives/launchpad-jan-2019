#include<iostream>
#include<cstring>
using namespace std;


int main(){
	//Character Array
	//terminate a char array with null character
	char a[100] = {'a','b','c','d','e','f','\0'};


	//another way
	char b[] = "Hello_World!";
	cout<<sizeof(b)<<endl;
	cout<<b<<endl;

	//input
	char c[100];
	//cin>>c;
	cin.getline(c,100);
	cout<<c<<endl;

	//find the length of the string.
	cout<<strlen(c)<<endl;

	
	//cout<<a<<endl;

	return 0;
}