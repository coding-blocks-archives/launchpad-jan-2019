#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(char *input){

	stack<char> s;
	//cout<<input<<endl;
	
	for(int i=0;input[i]!='\0';i++){
		char ch = input[i];
		if(ch!=']' and  ch!=')'){
			//cout<<"pushing "<<ch<<endl;
			s.push(ch);


		}
		else{
			if(!s.empty()){

				if(ch==']'){
					char top = s.top();
					
					if(s.top()=='['){
						return true;
					}
					else{
						while(!s.empty() and s.top()!='['){
							s.pop();
						}
						s.pop();
					}
				}
				if(ch==')'){
					
					if(s.top()=='('){
						//cout<<"Here";
						return true;
					}
					else{
						while(!s.empty() and s.top()!='('){
							//cout<<"popping "<<s.top()<<" ";
							s.pop();

						}
						//cout<<"poppting "<<"("<<endl;
						s.pop();
					}
				}
			}
		}
		
	}
	if(s.empty()==true){
		return false;
	}
	return true;
}

int main(){

	char input[100];
	cin>>input;

	if(isBalanced(input)){
		cout<<"Redundant";
	}
	else{
		cout<<"Not Redundant!";
	}

	return 0;
}
