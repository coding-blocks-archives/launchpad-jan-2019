#include<iostream>
#include<unordered_map>
using namespace std;

class trie;//

class node{
public:
	char data;
	unordered_map<char,node*> m;
	bool isterminal;

public:
	node(char d){
		data = d;
		isterminal = false;
	}
	friend class trie;
};
class trie{

	node*root;
public:
	trie(){
		root = new node('\0');
	}
	void addWord(char word[]){

		node*temp = root;
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m.count(ch)==0){
				node*n = new node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}
		temp->isterminal= true;
	}
	bool search(char word[]){
		node*temp = root;
		
		for(int i=0;word[i]!='\0';i++){
			char ch = word[i];

			if(temp->m.count(ch)==0){
				return false;
			}
			temp = temp->m[ch];
		}
		return temp->isterminal;
	}
};

int main(){

	char words[][10] = {"india","indian","no","news"};
	char w[10];
	cin>>w;

	trie t;
	for(int i=0;i<4;i++){
		t.addWord(words[i]);
	}

	if(t.search(w)){
		cout<<w<<" ~ FOUND!";
	}
	else{
		cout<<w<<" NOT FOUND";
	}

	return 0;
}