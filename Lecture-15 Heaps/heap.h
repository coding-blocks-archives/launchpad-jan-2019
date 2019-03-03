#include<vector>
using namespace std;

template<typename U,typename V,typename W>
class Heap{

	vector<int> v;
	bool minH;

	bool cmp(int a,int b){
		if(minH)
			return a>b;
		else
			return b>a;
	}
	void heapify(int i){
		int left = i<<1;
		int right = left+1;

		int ptr = i;
		if(left<v.size() and cmp(v[i],v[left])){
			ptr = left;
		}
		if(right<v.size() and cmp(v[ptr],v[right])){
			ptr = right;
		}

		if(i!=ptr){
			swap(v[ptr],v[i]);
			heapify(ptr);
		}
	}

public:
	Heap(bool mH=true){
		//Block 0th position
		v.push_back(-1);
		minH = mH;
	}
	void push(int d){

		v.push_back(d);
		int idx = v.size() -1;

		while(idx>1){
			int parent = idx/2;
			if(cmp(v[parent],v[idx])){
				swap(v[parent],v[idx]);
				idx = parent;
			}
			else{
				break;
			}
		}
	}

	void pop(){
		//Swap first and the last element
		int last = v.size()-1;
		swap(v[1],v[last]);
		v.pop_back();
		heapify(1);
	}

	bool empty(){
		return v.size()==1;
	}
	int top(){
		return v[1];
	}
};