#include<iostream>
#include "hashtable.h"
using namespace std;



int main(){
	hashtable<int> h;

	h.insert("Apple",100);
	h.insert("Mango",200);
	h.insert("Guava",40);
	h.insert("Grape",80);
	h.insert("Kiwi",190);

	h.show();

return 0;
}