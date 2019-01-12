#include<iostream>
using namespace std;


int main(){

	char a,b;

	//Read a sentence till new line character.
	char ch;
	int x,y;
	x= y = 0;

	ch = cin.get(); //read the first character
	while(ch!='\n'){
		
		switch(ch){
			case 'N':  y++;break;
			case 'W':  x--;break;
			case 'S':  y--;break;
			case 'E': x++;break;
		}
		ch = cin.get(); //read the next character
	}
	cout<<"X: "<<x<<" and Y: "<<y<<endl;

	return 0;

}