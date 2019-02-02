#include<iostream>
using namespace std;

void findPath(char maze[][10],int i,int j,int m,int n){
	//goal reached
	if(i==m and j==n){

		maze[m][n] = '*';
		for(int x=0;x<=m;x++){
			for(int y=0;y<=n;y++){
				cout<<maze[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	//out of bounds
	else if(i>m or j>n){
		return;
	}
	//X case
	else if(maze[i][j]=='X'){
		return;
	}
	//Rec Case

	maze[i][j] = '*'; 
	findPath(maze,i+1,j,m,n);
	findPath(maze,i,j+1,m,n);
	//Backtracking!
	maze[i][j] = '0';
	return;
	
}

int main(){

	char maze[10][10] = {
		"00XX0",
		"0X00X",
		"00000",
		"000X0",
		"0000X",
		"00X00"
	};
	findPath(maze,0,0,5,4);
	

	return 0;
}