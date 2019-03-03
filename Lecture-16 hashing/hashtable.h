#include<cstring>
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T> *next;

	node(string k,T val){
		key = k;
		value = val;
		next = NULL;
	}
	~node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template<typename T>
class hashtable{
	//Data Members
	node<T>** table;
	int cs;
	int ms;

	int hashFn(string key){

		int ans = 0;
		int p =1;

		for(int i=0;i<key.size();i++){
			ans += key[i]*p;
			p = p*37;

			p %= ms;
			ans %= ms;
		}
		return ans;
	}
	void rehash(){
		//create a new table of double capacity
		int oldms = ms;
		ms = ms*2; //+prime....
		cs = 0;
		node<T>**oldTable = table;
		table = new node<T>*[ms];
		for(int i=0;i<ms;i++){
			table[i] = NULL;
		}
		//iterate over old table to insert entries in the new table
		for(int i=0;i<oldms;i++){
			node<T>*temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
			//delete the ith linked list
			delete oldTable[i];
		}
		delete [] oldTable;
	}

public:
	hashtable(int ds=7){
		cs = 0;
		ms = ds;
		table = new node<T>*[ms];
		for(int i=0;i<ds;i++){
			table[i] = NULL;
		}
	}
	void insert(string key,T val){
		int idx = hashFn(key);

		node<T>*n = new node<T>(key,val);
		n->next = table[idx];
		table[idx] = n;
		cs++;

		float load_factor = (cs)/float(ms);
		if(load_factor>0.7){
			rehash();
		}
	}

	T* search(string key){
		int idx = hashFn(key);
		node<T>*temp = table[idx];
		while(temp!=NULL){
			if(temp->key ==key){
				return &temp->value;
			}
			temp= temp->next;
		}
		return NULL;
	}

	void erase(string key){
		//remve the node from linked list (homework)!
	}

	T& operator[](string key){
		//first step
		T* val = search(key);
		if(val==NULL){
			T obj;
			insert(key,obj);
		}
		//pakka hogi ...
		val = search(key);
		return *val;
	}

	void show(){

		for(int i=0;i<ms;i++){
			node<T>*temp = table[i];
			cout<<"Bucket "<<i<<"=";
			while(temp!=NULL){
				cout<<temp->key<<"-->";
				temp = temp->next;
			}
			cout<<endl;
		}
	}



};