#include<iostream>
#include<stack>
#include<stack>
using namespace std;

class Book{

public:
	string name;
	int price;
	Book(){

	}
	Book(string n,int p){
		name = n ;
		price = p;
	}
};

ostream& operator<<(ostream&a,Book&b){
	cout<<b.name<<" "<<b.price<<endl;
	return a;
}
ostream& operator<<(ostream&a,stack<Book> &sb){
		while(!sb.empty()){
		Book temp = sb.top();
		cout<<temp;
		sb.pop();
	}
	return a;

}

int main(){

	stack<char> s;

	for(int i=61;i<=65;i++){
		s.push(i);
	}


	//Empty
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

	//Stack of Books
	Book b1("C++",100);
	Book b2("Java++",300);
	Book b3("Python",200);

	stack<Book> sb;
	sb.push(b1);
	sb.push(b2);
	sb.push(b3);

	cout<<sb;


	return 0;
}