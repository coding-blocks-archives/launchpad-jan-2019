#include<iostream>
#include<cstring>
using namespace std;


class Student{

public:
	char *name;
	int marks;

	Student(char *n){
		//Dynamic Allocation of Array
		name = new char[strlen(name)+1];
		strcpy(name,n);
		marks = 10;
	}
	//Default Copy Constructor makes Shallow Copy!
	//Deep Copy
	Student(Student &s){
		name = new char[strlen(s.name)+1];
		strcpy(name,s.name);
	
		marks = s.marks;
	}
	//copy assignment operator for deep copy
	void operator=(Student &s){
		name = new char[strlen(s.name)+1];
		strcpy(name,s.name);
	
		marks = s.marks;
	}
	void print(){
		cout<<name<<endl;
		cout<<marks<<endl<<endl;
	}
	~Student(){
		delete [] name;
	}
};

int main(){

	Student s("ABC");
	Student s2(s);
	s2.marks += 11;

	s2.name[0] = 'B';
	s.print();
	s2.print();

	return 0;
}