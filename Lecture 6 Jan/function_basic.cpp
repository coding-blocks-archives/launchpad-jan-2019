#include<iostream>
using namespace std;

int square(int n){ //Function Declaration
	//cout<<n*n<<endl;
	return n*n; // Function Body/Definition
} 

float sqRoot(int n,int p){

	float ans = 0.0;
	float inc = 1.0;

	for(int times=1;times<=p+1;times++){

		while(ans*ans <=n){
			ans = ans + inc;
		}
		ans = ans-inc;
		inc = inc/10;
	}
	return ans;
}

bool isPrime(int n){

	//Root N Times
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void PrintAllPrime(int n){

	for(int j=1;j<=n;j++){
		if(isPrime(j)){
			cout<<j<<" ";
		}
	}
}


int main(){
	//Topic - Functions
	cout<<square(6)<<endl; //Function Call
	cout<<sqRoot(10,3)<<endl;
	cout<<sqRoot(25,2)<<endl;
	
	int n;
	cin>>n;

	PrintAllPrime(n);
	/*
	bool primeHai = isPrime(n);
	if(primeHai){
		cout<<"Prime No ";
	}
	else{
		cout<<"Not Prime";
	}*/

}