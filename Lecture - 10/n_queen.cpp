#include<iostream>
using namespace std;

bool isSafe(int board[][10],int n,int i,int j){
	//same col 
	for(int x=0;x<i;x++){
		if(board[x][j]==1){
			return false;
		}
	}

	//left diag 
	int x=i,y=j;
	while(x>=0 and y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}
	//right diag 
	x=i,y=j;
	while(x>=0 and y<n){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y++;
	}

	return true;
}

void placeQueen(int board[][10],int n,int i){
	//base case
	if(i==n){
		//print the board
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	//rec case
	for(int j=0;j<n;j++){
		if(isSafe(board,n,i,j)){
			board[i][j] = 1;
			placeQueen(board,n,i+1);
			board[i][j] = 0;
		}
	}
	return;
}

int countNqueen(int board[][10],int n,int i){
	//base case
	if(i==n){
		return 1;
	}
	int ways = 0;
	//rec case
		for(int j=0;j<n;j++){
		if(isSafe(board,n,i,j)){
			board[i][j] = 1;
			ways += countNqueen(board,n,i+1);
			board[i][j] = 0;
		}
	}
	return ways;
}


int main(){

	int n;
	cin>>n;

	int board[10][10] = {0};

	//placeQueen(board,n,0);
	cout<<countNqueen(board,n,0)<<endl;
}