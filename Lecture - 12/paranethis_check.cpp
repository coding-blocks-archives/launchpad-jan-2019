#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(char *input){

	stack<char> s;
	
	for(int i=0;input[i]!='\0';i++){
		char ch = input[i];
		if(ch=='(' or ch=='['){
			s.push(ch);
		}
		else if(ch==')'){
			if(!s.empty() and s.top()=='('){
				s.pop();
				continue;
			}
			else{
				return false;
			}

		}
		else if(ch==']'){
			if(!s.empty() and s.top()=='['){
				s.pop();
				continue;
			}
			else{
				return false;
			}

		}
	}
	if(s.empty()){
		return true;
	}
	return false;
}

int main(){

	char input[100];
	cin>>input;

	if(isBalanced(input)){
		cout<<"Yes!";
	}
	else{
		cout<<"No!";
	}

	return 0;
}
