#include <iostream>
using namespace std;

char firstNonRepeatingCharacter(string str) {
	//Homework


	return 'a' ;
}
void filterChar(int no,char a[]){
	//Extract the characters corresponding to set bits of that number
	int i = 0;
	while(no>0){
		int last_bit = (no&1);
		if(last_bit){
			cout<<a[i];
		}
		i++;
		no = no>>1;
	}

}

void subsequence(char *str){

	int n = strlen(str);
	for(int i=0;i<(1<<n);i++){
		filterChar(i,str);
		cout<<endl;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	char a[10];
	cin>>a;

	subsequence(a);
	return 0;
}