#include<iostream>
using namespace std;

template<typename T>
class Vector{

	int cs;
	int ms;
	T *arr;


public:
	Vector(int ds=10){
		cs = 0;
		ms = ds;
		arr = new T[ms]{0};
	}
	void push_back(int d){
		if(cs==ms){
			//double the space
			T *oldArr = arr;
			arr = new T[2*ms];
			ms = ms*2;

			for(int i=0;i<cs;i++){
				arr[i] = oldArr[i];
			}
			delete [] oldArr;
		}
		arr[cs] = d;
		cs++;
	}

	void pop_back(){
		if(cs>0){
			cs--;
		}
	}

	T operator[](int i){
		return arr[i];
	}
	int size(){
		return cs;
	}
	int capacity(){
		return ms;
	}
	void operator+(Vector&v2){
		for(int i=0;i<v2.size();i++){
			push_back(v2[i]);
		}
	}
};
ostream& operator<<(ostream&a,Vector<char> &v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return a;
}


int main(){

	Vector<char> v1,v2;
	v1.push_back(71);
	v1.push_back(72);
	v1.push_back(73);


	v2.push_back(74);
	v2.push_back(75);

	v1+v2;
	cout<<v1<<endl;
	cout<<v1.capacity()<<endl;

	return 0;
}