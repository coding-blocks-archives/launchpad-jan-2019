#include<iostream>
using namespace std;

void rotateA(int a[][10],int n){


	//Transpose!
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i<j){
				swap(a[i][j],a[j][i]);
			}
		}
	}


	//Reverse every row!
	for(int i=0;i<n;i++){
		int j = 0,k=n-1;
		while(j<k){
			swap(a[i][j],a[i][k]);
			j++; k--;
		}
	}

}

int main(){

	int a[10][10] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	//Rotate by 90 deg 
	int n;
	cin>>n;

	//Input
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}

	//Output
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	//rotate
	rotateA(a,n);


	//Output
	cout<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}




	return 0;
}