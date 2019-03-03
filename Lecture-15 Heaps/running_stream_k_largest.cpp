#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

void printHeap(priority_queue<int,vector<int>,greater<int> > h){

	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	cout<<endl;
	return;
}

int main(){


	int no;
	//min priority queue
	priority_queue<int,vector<int>,greater<int> > h;

	int k=3;
	int cs=0;

	while(scanf("%d",&no)!=EOF){
		//cout<<no<<" ";
		if(no!=-1){
			
			if(cs<k){
				h.push(no);
				cs++;
			}
			else if(no>h.top()){
				h.pop();
				h.push(no);
			}
		}
		else{
			cout<<"Query ";
			printHeap(h);
		}
	}

	return 0;
}