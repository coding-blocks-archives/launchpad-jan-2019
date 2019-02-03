#include<iostream>
#include<cstring>
using namespace std;

//blueprint
class Car{
	int price;
public:
	//Data Members
	char name[13];
		//Functions
	//1. Constructor (by default call)
	Car(){
		//override
		name[0] = '\0';
		price = 0;
	}
	Car(char *n,int p){
		//constructor overloading 
		strcpy(name,n);
		price = p;
	}
	//Getters and Setters
	void setPrice(int p){
		if(p>0){
			price = p;
		}
	}
	//2. Copy Constructor
	Car(Car &X){
		//<<"In copy constructor";
		price = X.price;
		strcpy(name,X.name);
	}
	//3. Copy Assignment Operator
	void operator=(Car &X){
		price = X.price;
		strcpy(name,X.name);
	}

	int getPrice(){
		return price;
	}
	void print() const{
		cout<<"Name :"<<name<<endl;
		cout<<"Price :"<<price<<endl;
	}
	//Operator Overloading
	void operator+(int inc){
		price += inc;
	}
	void operator!(){
		cout<<name<<" not in stock!";
	}
	void operator[](string s){
		cout<<name<<" is owned by "<<s<<endl;
	}
	void operator()(string n){
		cout<<name<<" is Lit()!"<<n<<endl;
	}


	//4. Destructor
	~Car(){
		//cout<<"Destroying car "<<name<<endl;
	}
};
//-------------Define Overloaded Operators here also

ostream& operator<<(ostream&a, Car &b){
	b.print();
	return a;
}
istream& operator>>(istream&a, Car&b){
	char name[13];
	int p;
	cin>>name>>p;

	strcpy(b.name,name);
	b.setPrice(p);
	return a;
}


int main(){

	Car x;
	Car y("BMW",200);

	Car z(y); //copy constructor
	Car z2 = y; //copy constructor

	Car z3; //default constructor
	
	y.setPrice(150);
	strcpy(y.name,"Audi");
	z3 = y; // copy assignment operator
	z3.print();

	z3+20;
	cout<<z3.getPrice()<<endl;

	!z3;

	z3["Uber"];
	z2["Ola"];
	//z3();

	Car fun("Safari",100); //Parametrised Constructor
	fun("Delhi"); //Overloaded () Operator fun --> object -->behaving like a function --> functor

	cin>>fun>>z3; //cascading 
	cout<<fun<<z3; //ostream
	






	return 0;
}
