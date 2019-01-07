#include<iostream>
using namespace std;


int main(){

	char a,b;

	//Read a sentence till new line character.
	char ch;
	ch = cin.get(); //read the first character
	while(ch!='.'){
		cout<<ch;
		ch = cin.get(); //read the next character
	}

	return 0;

}