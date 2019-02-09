#include<iostream>
using namespace std;

class Complex{
public:
	int r;
	int i;

	Complex(){
		r = i = 0;
	}
	Complex(int r,int i){
		this->r = r;
		this->i = i;
	}
	Complex operator+(Complex b){
		Complex c;
		c.r = r + b.r;
		c.i = i + b.i;
		return c;
	}
	int operator[](char c){
		if(c=='r'){
			return r;
		}
		else{
			return i;
		}
	}
};

ostream& operator<<(ostream &a,Complex &c){
	cout<<c.r<<" + "<<c.i<<"i"<<endl;
	return a;
}
istream& operator>>(istream &a,Complex &c){
	cin>>c.r>>c.i;
	return a;
}

int main(){

	Complex c,c1,c2;
	cin>>c1>>c2;
	Complex c3;
	c3 = c1 +c2;
	cout<<"Comple No is "<<c3<<endl;

	return 0;
}