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

int main(){

	char a[100];
	int n;
	//cin>>n;
	
	readline(a,100,'\n');
	cout<<a<<endl;

	/*
	cin.get();

	int largest_len = 0;
	char largest_string[100];

	for(int i=0;i<n;i++){
		cin.getline(a,100);
		int l = strlen(a);
		
		if(l>largest_len){
			largest_len = l;
			strcpy(largest_string,a);
		}
	}
	cout<<largest_len<<endl;
	cout<<largest_string<<endl;
	*/
	return 0;

}