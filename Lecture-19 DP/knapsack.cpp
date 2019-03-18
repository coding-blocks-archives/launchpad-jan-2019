#include<iostream>
using namespace std;

int knapasack_profit(int wts[],int prices[],int n,int C){
	//base case
	if(C==0 or n==0){
		return 0;
	}
	//rec case
	int inc=0,exc=0;

	//limited qty case //infinite qty case 
	if(C-wts[n-1]>=0){
		inc = prices[n-1] + knapasack_profit(wts,prices,n-1,C-wts[n-1]);
	}
	exc = 0 + knapasack_profit(wts,prices,n-1,C);
	return max(inc,exc);
}

int knapasack_profit_bu(int wts[],int prices[],int n,int C){

	int dp[100][100] = {0};

	for(int i=1;i<=n;i++){
		for(int j=1;j<=C;j++){
			int ans = 0;
			if(wts[i-1]<=j){
				ans = prices[i-1] + dp[i-1][j-wts[i-1]];
			}
			int exc = dp[i-1][j];
			dp[i][j] = max(ans,exc);
		}
	}
	return dp[n][C];
}

int knapasack_profit_buo(int wts[],int prices[],int n,int C){

	int dp[2][100] = {0};

	for(int i=1;i<=n;i++){
		for(int j=1;j<=C;j++){
			int ans = 0;

			if(wts[i-1]<=j){
				ans = prices[i-1] + dp[(i-1)%2][j-wts[i-1]];
			}
			int exc = dp[(i-1)%2][j];
			dp[i%2][j] = max(ans,exc);
		}
	}
	return dp[n%2][C];
}

int main(){

	int item_wt[] = {3,1,2,5};
	int item_price[] = {25,8,10,15};
	cout<<knapasack_profit_buo(item_wt,item_price,4,8)<<endl;

	return 0;
}