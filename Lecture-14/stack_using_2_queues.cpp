#include<iostream>
#include<queue>
using namespace std;


class Stack{

	queue<int> q1,q2;
	int cs;

public:
	Stack(){
			cs = 0;
	}
	void push(int data){
		
		if(q1.empty()){
			q2.push(data);
		}
		else if(q2.empty()){
			q1.push(data);
		}
		cs++;

	}
	void pop(){
		if(!q1.empty()){
			while(q1.size()!=1){
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		}

		else if(!q2.empty()){
			while(q2.size()!=1){
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
		cs--;
	}
	int top(){
		if(!q1.empty()){
			while(q1.size()!=1){
				q2.push(q1.front());
				q1.pop();
			}
			int t = q1.front();
			q1.pop();
			q2.push(t);
			return t;
		}

		else if(!q2.empty()){
			while(q2.size()!=1){
				q1.push(q2.front());
				q2.pop();
			}
			int t = q2.front();
			q2.pop();
			q1.push(t);
			return t;
		}
	}
	bool empty(){
		return cs==0;
	}
};

int main(){

	Stack s;
	for(int i=1;i<=5;i++){
		s.push(i);
	}
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	return 0;
}