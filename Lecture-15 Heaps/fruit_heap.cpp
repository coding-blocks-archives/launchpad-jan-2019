#include<iostream>
#include<queue>
using namespace std;

class Fruit{
public:
	string name;
	int price;
public:
	Fruit(){

	}
	Fruit(string n,int p){
		name = n;
		price = p;
	}
	
};

class FruitCompare{
public:
	bool operator()(Fruit a,Fruit b){
		//cout<<a<<" fruit is tasty than "<<b;
		return a.price>b.price;
	}

};
int main(){

	Fruit myFruit;
	//myFruit("apple","guava"); //functional_object = functor

	

	priority_queue<int> hmax; //maxheap
	priority_queue<Fruit,vector<Fruit>, FruitCompare > h; //minheap


	int arr[] = {1,5,12,7,9,0};
	string names[] = {"apple","mango","guava","chiku","strawberry","papaya"};
	int n = sizeof(arr)/sizeof(int);

	for(int i=0;i<n;i++){
		Fruit fruit(names[i],arr[i]);
		h.push(fruit);
	}
	while(!h.empty()){
		Fruit f = h.top();
		cout<<f.name<<" and "<<f.price<<endl;
		h.pop();
	}

	

	return 0;
}