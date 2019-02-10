#ifndef STACK_H
#define STACK_H

template<typename T>
class node{
public:
	T data;
	node<T>*next;

	node(T d){
		data = d;
		next = NULL;
	}
};

template<typename T>
class Stack{
	node<T> *head;

public:
	Stack(){
		head = NULL;
	}
	void push(T d){
		if(head==NULL){
			head = new node<T>(d);
			return;
		}
		node<T> *n = new node<T>(d);
		n->next = head;
		head = n;
	}
	void pop(){
		if(head!=NULL){
			node<T>*temp = head;
			head = head->next;
			delete temp;
		}
	}
	T top(){
		return head->data;
	}
	bool empty(){
		return head==NULL;
	}
};

#endif