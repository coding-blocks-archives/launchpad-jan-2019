#include<iostream>
#include "queue.h"
using namespace std;


int main(){

	Queue q;

	for(int i=1;i<=7;i++){
		q.push(i);
	}
	q.pop();
	q.push(8);

	while(!q.isEmpty()){
		cout<<q.getfront()<<" ";
		q.pop();
	}

	return 0;
}
