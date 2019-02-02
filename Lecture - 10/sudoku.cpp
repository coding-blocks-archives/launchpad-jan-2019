#include<iostream>
using namespace std;

bool isSafe(int mat[][9],int i,int j,int n,int no){

	//same row or col
	for(int x=0;x<9;x++){
		if(mat[i][x]==no or mat[x][j]==no){
			return false;
		}
	}
	//subgrid
	int sx,sy;
	sx = (i/3)*3;
	sy = (j/3)*3;

	//iterate over subgrid
	for(int x=sx;x<sx+3;x++){
		for(int y=sy;y<sy+3;y++){
			if(mat[x][y]==no){
				return false;
			}
		}
	}
	return true;
}


bool solveSudoku(int mat[][9],int i,int j,int n){
	if(i==n){
		//print the matrix
		for(int x=0;x<9;x++){
			for(int y=0;y<9;y++){
				cout<<mat[x][y]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//Rec Case
	if(j==n){
		return solveSudoku(mat,i+1,0,n);
	}
	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1,n);
	}
	//rec case
	for(int no=1;no<=9;no++){
		if(isSafe(mat,i,j,n,no)){
			cout<<"no "<<no<<endl;
			mat[i][j] = no;
			bool solveHua = solveSudoku(mat,i,j+1,n);
			if(solveHua){
				return true;
			}

		}
	}
	mat[i][j] = 0;
	return false;
}

int main(){


		int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

        solveSudoku(mat,0,0,9);

        return 0;
}