#include<iostream>
#include<cstring>
using namespace std;

void readline(char a[],int max_size,char delim){
	//Try to complete
	//cin or cin.get()?

	for(int i=0;i<max_size;i++){
		char ch = cin.get();
		if(ch==delim){
			a[i] = '\0';
			break;
		}
		a[i] = ch;
	}
}

bool isPalindrome(char a[]){
	//to check if a string is palindrome or not
	int i = 0;
	int j = strlen(a) - 1;

	while(i<j){
		if(a[i]!=a[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
bool isPermuation(char a[],char b[]){

	int freq[27]={0};
	char ch;
	//Freq update for a
	for(int i=0;a[i]!='\0';i++){
		ch = a[i];
		freq[ch-'a']++; 
	}
	//freq update for b
	for(int i=0;b[i]!='\0';i++){
		ch = b[i];
		freq[ch-'a']--; 
	}

	//check for all zeroes
	for(int i=0;i<27;i++){
		if(freq[i]!=0){
			return false;
		}
	}
	return true;
}

int main(){

	char a[100],b[100];

	readline(a,100,'\n');
	readline(b,100,'\n');

	if(isPermuation(a,b)){
		cout<<"yes!";
	}
	else{
		cout<<"Not a Permuation!";
	}

	
	return 0;

}