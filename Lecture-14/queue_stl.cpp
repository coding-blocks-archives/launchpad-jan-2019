#include<iostream>
#include<queue>
using namespace std;


int main(){

	queue<int> q;

	for(int i=1;i<=7;i++){
		q.push(i);
	}
	q.pop();
	q.push(8);
	cout<<q.size()<<endl;ṭ

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	return 0;
}
