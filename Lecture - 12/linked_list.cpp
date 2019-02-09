#include<iostream>
using namespace std;

class node{

public:
	int data;
	node* next;

public:
	//Node Constructor
	node(int d){
		data = d;
		next = NULL;
	}
};

/*
class LinkedList{
	node*head;
};
*/
void insertAtHead(node*&head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}

	//otherwise!
	node* n = new node(data);
	n->next = head;
	head = n;
}
//Insert at tail
void insertAtTail(node*&head,int data){

	if(head==NULL){
		head = new node(data);
		return;
	}
	node*t = head;
	//bring t pointer to the last node
	while(t->next!=NULL){
		t = t->next;
	}
	//last node ->next attach new node
	t->next = new node(data);
	return;
}
int length(node*head){
	int l=0;
	while(head!=NULL){
		l++;
		head = head->next;
	}
	return l;
}

void insertInMiddle(node*&head,int data,int pos){
	if(pos==0){
		insertAtHead(head,data);
		return;
	}
	if(pos>length(head)){
		insertAtTail(head,data);
		return;
	}
	//Middle
	node*t = head;
	for(int jump=1;jump<=pos-1;jump++){
		t = t->next;
	}
	node* n = new node(data);
	n->next = t->next;
	t->next = n;
}

int search1(node*head,int key){
//Iterative Search
	node*t = head;
	int idx = 0;
	while(t!=NULL){
		if(t->data==key){
			return idx;
		}
		idx++;
		t = t->next;
	}
	return -1;
}

int search2(node*head,int key){
//Recursive Search
	//base case
	if(head==NULL){
		return -1;
	}

	//rec case
	if(head==key){
		return 0;
	}
	else{
		int l = search2(head->next,key);
		if(l!=-1){
			return 1 + l;
		}
		return l;
	}
}
void reverse(node*&head){
	//iterative way
	

}
node* reverse_rec(node*head){
	//recursive way


}

//Let us print our linked list
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<endl;
}


int main(){

	//Linked List
	node*head = NULL;
	/*
	insertAtHead(head,5);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	print(head);
	*/
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,5);
	insertAtHead(head,0);
		print(head);
	insertInMiddle(head,4,4);
	
	print(head);



	return 0;
}