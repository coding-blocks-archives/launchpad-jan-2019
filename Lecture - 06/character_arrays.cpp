#include<iostream>
using namespace std;


int main(){

	int a[10][10] = {0};

	int r,c;
	cin>>r>>c;
	//Input
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>a[i][j];
		}
	}

	//Output
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}