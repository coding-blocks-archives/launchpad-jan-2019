#include<iostream>
using namespace std;

int profit(int *wines,int dp[][100],int s,int e,int y){

	if(s>e){
		return 0;
	}
	if(dp[s][e]!=0){
		return dp[s][e];
	}

	//Rec Case
	int op1 = wines[s]*y + profit(wines,dp,s+1,e,y+1);
	int op2 = wines[e]*y + profit(wines,dp,s,e-1,y+1);
	return dp[s][e]=max(op1,op2);
}

int main(){

	int dp[100][100] ={0};

	int wines[] = {2,3,5,1,4};
	int n = sizeof(wines)/sizeof(int);
	cout<<profit(wines,0,n-1,1);

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}